#pragma once
#include "Functor.h"
#include "Tree.h"
#include <vector>


template<typename T>
std::vector<T> search(typename Tree<T>::Iterator begin, typename Tree<T>::Iterator end, T& obj, Functor& f)
{

	std::vector<T> objVector;

	for (begin; begin != end; begin++)
	{
		if (f(*begin, obj)) objVector.push_back(*begin);
	}
	return objVector;
}

template<typename Iterator>
int size(Iterator begin, Iterator end)
{
	int i = 0;
	for (begin; begin != end; begin++)
		++i;
	return i;
}

