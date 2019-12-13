#include "pch.h"
#include "Interface.h"
#include <Windows.h>

int main()
{
	system("color 3E"); //установка цветаа фона консоли и цвета шрифта
	
	//установка русского языка
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	
	Interface<int> obj;
	obj.menu(); //вызов меню выбора класса для дальнейшей работы
}

