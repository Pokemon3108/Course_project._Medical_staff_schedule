#pragma once
#include "pch.h"
#include "Doctor.h"
#include "ServiceStaff.h"
#include "Nurse.h"
#include "AdministrativeStaff.h"
#include "Functor.h"
#include "Tree.h"
#include "Algorithm.h"



using std::cout;
using std::endl;
using std::cin;


template <typename T>
class Interface
{
public:

	Interface()
	{}
	~Interface()
	{}

	void menu();
	bool action();
	void searchMenu(T& obj, Functor& f);
	//void chooseGraphicType();
	friend class Functor;
};

template<typename T>
void Interface<T>::menu()
{

	int n;

	do
	{
		cout << "Выберите тип: " << endl;
		cout << "1-Доктор" << endl;
		cout << "2-Медсестра" << endl;
		cout << "3-Специалист в других сферах" << endl;
		cout << "4-Обслуживающий персонал" << endl;
		cout << "0-Выйти из программы" << endl;
		cin >> n;

		switch (n)
		{
		case 1:
		{
			Interface<Doctor> obj;
			if (!obj.action()) return;
		}
		break;

		case 2:
		{
			Interface<Nurse> obj;
			if (!obj.action()) return;
		}
		break;

		case 3:
		{
			Interface<AdministrativeStaff> obj;
			if (!obj.action()) return;
		}
		break;
		case 4:
		{
			Interface<ServiceStaff> obj;
			if (!obj.action()) return;
		}
		break;
		case 0:
			break;
		}

	} while (n);

}

template<typename T>
inline bool Interface<T>::action()
{
	Tree<T> tree;
	int n;
	do
	{
		cout << "\n1-Добавить объект" << endl;
		cout << "2-Вывести информацию о всех объектах" << endl;
		cout << "3-Удалить объект" << endl;
		cout << "4-Удалить всё" << endl;
		cout << "5-Найти объекты по всем параметрам" << endl;
		cout << "6-Найти объект по выбранным параметрам" << endl;
		cout << "7-Количество объектов" << endl;
		cout << "8-Осуществить операции с объектами других классов" << endl;
		cout << "0-Конец программы" << endl;
		cin >> n;


		switch (n)
		{

		case 1:
		{
			T obj;
			cout << "\nВведите объект" << endl;
			cin >> obj;
			tree.push(obj);
			break;
		}

		case 2:
		{
			T obj;
			int a;
			cout << "1-График работы" << endl << "2-График дежурств" << endl;
			cin >> a;
			obj.tableLines(cout);
			obj.table(cout);
			obj.tableGraphic(cout);
			switch (a)
			{
			case 1:
				tree.show(0);
				break;
			case 2:
				tree.show(1);
				break;
			}
			break;
		}

		case 3:
		{
			T obj;
			cout << "\nВведите объект" << endl;
			cin >> obj;
			tree.pop(obj);
			break;
		}

		case 4:
			tree.destroyTree(tree.getRoot());
			break;

		case 5:
		{
			T obj;
			Functor functorObj;
			searchMenu(obj, functorObj);
			std::vector<T> objVector = search(tree.begin(), tree.end(), obj, functorObj);
			if (objVector.size())
			{
				obj.table(cout);

				typename std::vector<T>::iterator it;
				for (it = objVector.begin(); it != objVector.end(); it++)
					cout << (*it);
			}
			break;
		}
		case 6:
		{
			T obj;
			cout << "\nВведите объект" << endl;
			cin >> obj;
			Node<T>* temp = tree.search(obj);
			if (!temp) cout << "Такого элемента не существует";
			else cout << "Элемент был найден";
		}
		case 7:
		{

			int s = size(tree.begin(), tree.end());
			std::cout << "Количество работников данной сферы=" << s << endl;
			break;
		}
		case 8:
			return 1;
		case 0:
			return 0;
		}
	} while (n);
	return 1;

}

template<typename T>
void Interface<T>::searchMenu(T& obj, Functor & f)
{
	Functor func = f;
	int n, i;
	do
	{
		obj.chooseParameters();
		cin >> n;
		std::string strForSet = obj.getParameter(n);
		func.getSetFields().insert(strForSet);
		cout << "Выбрать ещё один параметр:" << endl << "1-Да" << endl << "0-Нет" << endl;
		cin >> i;
	} while (i);
	f = func;
}


//template<typename T>
//void Interface<T>::informationForOutput()
//{
//	T obj;
//	obj.tableLines(cout);
//	obj.table(cout);
//	obj.tableGraphic(cout);
//	tree.showInOrder(tree.getRoot());
//}


