#pragma once
#include "pch.h"

class Exception
{
protected:
	std::string errorText;
public:
	Exception(std::string str) : errorText(str)
	{}
	~Exception()
	{};

	std::string what();
};
