#pragma once
#include "Tree.h"
#include "pch.h"

template<typename T>
class Cancel
{
private:
	string action;
	T obj;
	T edittedObj;
public:
	Cancel() = default;
	~Cancel() {}
	Cancel(string act, T obj_, T editted_obj) : action(act), obj(obj_), edittedObj(editted_obj) {}
	Cancel(string act, T obj_) : action(act), obj(obj_) {}
	Cancel(const Cancel& obj_) : action(obj_.action), obj(obj_.obj), edittedObj(obj_.edittedObj) {}
	
	void cancelAction(Tree<T>& tree);
};


template<typename T>
void Cancel<T>::cancelAction(Tree<T> & tree)
{
	if (action == "push") tree.pop(obj);
	else if (action == "pop") tree.push(obj);
	else
	{
		Node<T>* temp = tree.search(edittedObj);
		temp->data = obj;
	}
}


