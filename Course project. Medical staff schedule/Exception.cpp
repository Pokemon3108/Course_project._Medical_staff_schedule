#include "pch.h"
#include "Exception.h"

std::string Exception::what()
{
	return errorText;
}
