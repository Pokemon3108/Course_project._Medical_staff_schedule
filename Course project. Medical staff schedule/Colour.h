#pragma once
#include <Windows.h>
#include "pch.h"

void SetColor(int text, int background); //устанавливает цвет в консоли

template<int txt = 14, int bg = 3> //шаблон для установления цвета консоли в потоке вывода
std::ostream& color(std::ostream &text) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | txt));
	return text;
}
