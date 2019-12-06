#include "pch.h"
#include "Interface.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Interface<int> obj;
	obj.menu();
	system("pause");
}

