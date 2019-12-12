#pragma once
#include <Windows.h>
#include "pch.h"

void SetColor(int text, int background); //������������� ���� � �������

template<int txt = 14, int bg = 3> //������ ��� ������������ ����� ������� � ������ ������
std::ostream& color(std::ostream &text) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | txt));
	return text;
}
