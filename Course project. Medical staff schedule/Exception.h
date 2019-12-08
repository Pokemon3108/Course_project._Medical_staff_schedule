#pragma once
#include "pch.h"

class Exception
{
protected:
	string errorText;
public:
	Exception(string str) : errorText(str)
	{}
	~Exception()
	{}

	string what();
};
