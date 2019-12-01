#include "pch.h"
#include "Interface.h"
#include <Windows.h>

int main()
{
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Interface<int> obj;
	obj.menu();
	/*string str2 = "ывыв";
	string str1 = "фы";
	graphic gr1, gr2;
	gr1.hour1 = 12;
	gr1.hour2 = 13;
	gr1.weekday = "Среда";
	gr2.hour1 = 13;
	gr2.hour2 = 16;
	gr2.weekday = "Пятница";
	list<graphic> l;
	l.push_back(gr1);
	l.push_back(gr2);
	Doctor d(str1, str1, str1, str1, str1,str1, l, l);
	d.tableLines(cout);
	d.table(cout);
	d.tableGraphic(cout);
	Doctor d1(str2, str2, str2, str1, str1,str1 ,l, l);
	Tree<Doctor> tree;
	tree.push(d);
	tree.push(d1);
	tree.show(0);
	cout << endl;

	d.editGraphic("Среда", 1);
	
	tree.show(1);*/
}

