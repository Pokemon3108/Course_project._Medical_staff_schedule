#include "pch.h"
#include "Interface.h"
#include <Windows.h>

int main()
{
	system("color 3E");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Interface<int> obj;
	obj.menu();
}

