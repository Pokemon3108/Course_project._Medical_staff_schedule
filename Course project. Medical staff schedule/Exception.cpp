#include "pch.h"
#include "Exception.h"

string Exception::what()
{
	return errorText;
}
