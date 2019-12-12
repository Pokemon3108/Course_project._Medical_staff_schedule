#pragma once
#include "pch.h"

class Exception
{
protected:
	string errorText; //текст ошибки
public:
	Exception(string str) : errorText(str)
	{}
	~Exception()
	{}

	string what(); //возвращает текст ошибки
};
