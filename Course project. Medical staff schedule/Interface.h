#pragma once
#include "pch.h"
#include "Doctor.h"
#include "ServiceStaff.h"
#include "Nurse.h"
#include "AdministrativeStaff.h"
#include "Functor.h"
#include "Tree.h"
#include "Algorithm.h"

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
		cout << "�������� ���: " << endl;
		cout << "1-������" << endl;
		cout << "2-���������" << endl;
		cout << "3-���������� � ������ ������" << endl;
		cout << "4-������������� ��������" << endl;
		cout << "0-����� �� ���������" << endl;
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
bool Interface<T>::action()
{
	Tree<T> tree;
	int n;
	do
	{
		cout << "\n1-�������� ������" << endl;
		cout << "2-������� ���������� � ���� ��������" << endl;
		cout << "3-������� ������" << endl;
		cout << "4-������� ��" << endl;
		cout << "5-����� ������� �� ���� ����������" << endl;
		cout << "6-����� ������ �� ��������� ����������" << endl;
		cout << "7-���������� ��������" << endl;
		cout << "8-��������������� ������" << endl;
		cout << "9-����������� �������� � ��������� ������ �������" << endl;
		cout << "0-����� ���������" << endl;
		cin >> n;


		switch (n)
		{

		case 1:
		{
			T obj;
			cout << "\n������� ������" << endl;
			cin >> obj;
			tree.push(obj);
			break;
		}

		case 2:
		{
			T obj;
			int a;
			cout << "1-������ ������" << endl << "0-������ ��������" << endl;
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
			cout << "\n������� ������" << endl;
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
			cout << "\n������� ������" << endl;
			cin >> obj;
			Node<T>* temp = tree.search(obj);
			if (!temp) cout << "������ �������� �� ����������";
			else cout << "������� ��� ������";
		}
		case 7:
		{

			int s = size(tree.begin(), tree.end());
			std::cout << "���������� ���������� ������ �����=" << s << endl;
			break;
		}
		case 8:
		{
			rewind(stdin);
			T obj;
			string str;
			cout << "������� ���:";
			std::getline(cin, str);
			obj.setFirstName(str);
			rewind(stdin);
			cout << "������� �������:";
			std::getline(cin, str);
			obj.setSurname(str);
			rewind(stdin);
			cout << "������� ��������:";
			std::getline(cin, str);
			obj.setFatherName(str);
			Node<T>* objPtr = tree.search(obj);
			if (!objPtr)
			{
				cout << "������� ������� �� ����������" << endl;
				break;
			}
			cout << "�������� �������� ��� ��������������:" << endl;
			obj.chooseParameters();
			int parameter;
			cin >> parameter;
			objPtr->data.edit(parameter);
			break;
		
		}
		case 9:
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
		cout << "�������� ��������� ��� ������:" << endl;
		obj.chooseParameters();
		cin >> n;
		std::string strForSet = obj.getParameter(n);
		func.getSetFields().insert(strForSet);
		cout << "������� ��� ���� ��������:" << endl << "1-��" << endl << "0-���" << endl;
		inputNumber(cin, i, 0, 1);
	} while (i);
	f = func;
}


