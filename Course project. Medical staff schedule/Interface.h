#pragma once
#include "pch.h"
#include "Doctor.h"
#include "ServiceStaff.h"
#include "Nurse.h"
#include "AdministrativeStaff.h"
#include "Functor.h"
#include "Tree.h"
#include "Algorithm.h"
#include "Cancel.h"
#include "File.h"
#include "FileError.h"

template <typename T>
class Interface
{
public:

	Interface()
	{}
	~Interface()
	{}

	void menu(); //меню выбора типа объекта для дальнейшей работы
	bool action(const char* filename); //выбор действия, которое необходимо произвести с объектом
	void searchMenu(T& obj, Functor& f); //меню поиска по определённому параметру
	void vectorOutput(std::vector<T> vec); //вывод вектора объектов
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
		cout << "3-Члены административно-технического персонала" << endl;
		cout << "4-Обслуживающий персонал" << endl;
		cout << "0-Выйти из программы" << endl;
		inputNumber(cin, n, 0, 4);
		system("cls");
		switch (n)
		{
		case 1:
		{
			Interface<Doctor> obj;
			if (!obj.action("..\\files\\Doctor.txt")) return;
		}
		break;

		case 2:
		{
			Interface<Nurse> obj;
			if (!obj.action("..\\files\\Nurse.txt")) return;
		}
		break;

		case 3:
		{
			Interface<AdministrativeStaff> obj;
			if (!obj.action("..\\files\\AdministrativeStaff.txt")) return;
		}
		break;
		case 4:
		{
			Interface<ServiceStaff> obj;
			if (!obj.action("..\\files\\ServiceStaff.txt")) return;
		}
		break;
		case 0:
			break;
		}

	} while (n);

}

template<typename T>
bool Interface<T>::action(const char* filename)
{
	stack <Cancel<T>> st;
	Tree<T> tree;
	File<T> file;
	//file.openForRead(filename);
	openForRead(file.getIn(),filename);
	//bool a=file.getin().is_open();
	file.readFromFile(tree);
	int n;
	do
	{
		cout << "1-Добавить работника" << endl;
		cout << "2-Вывести информацию о всех работниках выбранной сферы" << endl;
		cout << "3-Удалить работника" << endl;
		cout << "4-Удалить всё" << endl;
		cout << "5-Найти работников по выбранным параметрам" << endl;
		cout << "6-Количество работников" << endl;
		cout << "7-Отредактировать работника" << endl;
		cout << "8-Отменить последнее действие" << endl;
		cout << "9-Осуществить операции с работниками других сфер" << endl;
		cout << "0-Конец программы" << endl;

		inputNumber(cin, n, 0, 9);
		system("cls");

		switch (n)
		{

		case 1:
		{
			T obj;
			cout << "Введите информацию о работнике:" << endl;
			cin >> obj;
			Node<T>* temp = tree.search(obj);
			if (temp) cout << "Работника с таким именем уже существует" << endl;
			else {
				tree.push(obj);
				st.push(Cancel<T>("push", obj));
			}
			break;
		}

		case 2:
		{
			T obj;
			int a;
			cout << "1-График работы" << endl << "0-График дежурств" << endl;
			inputNumber(cin, a, 0, 1);
			obj.tableLines(cout);
			obj.table(cout);
			obj.tableGraphic(cout);
			tree.show(a);
			obj.tableLines(cout);
			break;
		}

		case 3:
		{
			T obj;
			cout << "Введите работника" << endl;
			obj.inputFullName(); //ввели полное имя
			Node<T>* temp = tree.search(obj); //нашли объект с таким именем
			if (temp)
			{
				obj = temp->data; //записали его в объект
				tree.pop(obj); //удалили его
				st.push(Cancel<T>("pop", obj));
			}
			else cout << "Работника с таким именем не существует" << endl;
			break;
		}

		case 4:
		{
			cout << "Вы уверены, что хотите удалить всё? Отменить данное действие будет невозможно" << endl;
			string str;
			inputYesNo(cin, str);
			if (str == "да" || str == "Да")
			{
				tree.destroyTree(tree.getRoot());
				while (!st.empty()) st.pop();
			}
			break;
		}

		case 5:
		{
			T obj;
			Functor functorObj;
			searchMenu(obj, functorObj);
			std::vector<T> objVector = search(tree.begin(), tree.end(), obj, functorObj);
			if (objVector.size())
				vectorOutput(objVector);
			
			else cout << "Работников с данными параметрами не найдено";
			break;
		}
		case 6:
		{

			int s = size(tree.begin(), tree.end());
			std::cout << "Количество работников данной сферы=" << s << endl;
			break;
		}
		case 7:
		{
			T obj;
			obj.inputFullName();
			Node<T>* objPtr = tree.search(obj);
			if (!objPtr)
			{
				cout << "Работника с таким именем не существует" << endl;
				break;
			}
			obj = objPtr->data; //в obj хранится значение до редактирования
			cout << "Выберите параметр для редактирования:" << endl;
			obj.chooseParameters();
			int parameter;
			if (filename=="..\\files\\Doctor.txt") inputNumber(cin, parameter, 1, 8);
			else inputNumber(cin, parameter, 1, 7);
			objPtr->data.edit(parameter);
			st.push(Cancel<T>("edit", obj, objPtr->data)); //заносим в стек объекты до редактирования и после
			break;

		}
		case 8:
		{
			if (st.size())
			{
				Cancel<T> action(st.top());
				action.cancelAction(tree);
				st.pop();
			}
			else cout << "Последние действия отменить нельзя" << endl;
			break;
		}
		case 9:
		case 0:
		{
			string str;
			std::cout << "Сохранить изменения?\n";
			inputYesNo(cin, str);
			if (str == "да" || str=="Да")
			{
				/*std::ofstream out(filename);
				tree.writeToFile(tree.getRoot(), out);*/
				//file.openForWrite(filename);
				openForWrite(file.getOut(),filename);
				file.writeToFile(tree.getRoot());
			}
			else return n;
		}
		
		}
		system("pause");
		system("cls");
	} while (n);
	return 0;
}


template<typename T>
void Interface<T>::searchMenu(T& obj, Functor & f)
{
	Functor func = f;
	int i;
	do
	{
		int parameter;
		cout << "Выберите параметры для поиска:" << endl;
		obj.chooseParameters();
		if (typeid(T)==typeid(Doctor)) inputNumber(cin, parameter, 1, 8);
		else inputNumber(cin, parameter, 1, 7);

		std::string strForSet = obj.getParameter(parameter);
		func.getSetFields().insert(strForSet);
		
		cout << "Выбрать ещё один параметр:" << endl << "1-Да" << endl << "0-Нет" << endl;
		inputNumber(cin, i, 0, 1);
	} while (i);
	f = func;
}

template<typename T>
void Interface<T>::vectorOutput(std::vector<T> vec)
{
	T obj;
	int act;
	cout << "0-График дежурств\n" << "1-График работы\n" << "2-Продолжить далее\n" << endl;
	inputNumber(cin, act, 0, 2);
	do
	{
		obj.tableLines(cout);
		obj.table(cout);
		obj.tableGraphic(cout);
		typename std::vector<T>::iterator it;
		for (it = vec.begin(); it != vec.end(); it++)
		{
			cout << (*it);
			it->outputGraphic(cout, bool(act));
			cout << endl;

		}
		obj.tableLines(cout);
		cout << "0-График дежурств\n" << "1-График работы\n" << "2-Продолжить далее\n" << endl;
		inputNumber(cin, act, 0, 2);
	} while (act != 2);
}
