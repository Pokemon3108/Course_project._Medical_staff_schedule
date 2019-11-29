#include "pch.h"
#include <iostream>
#include "Interface.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Interface<int> obj;
	obj.menu();
}

