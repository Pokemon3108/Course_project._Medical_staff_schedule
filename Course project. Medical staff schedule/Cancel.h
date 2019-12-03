#pragma once
#include "Tree.h"
#include "pch.h"

template<typename T1, typename T2>
class Cancel
{
private:
	string action;
	T1 obj;
	T2 edittedObj;
public:
	Cancel() = default;
	~Cancel() {}
	Cancel(string act, T1 obj_, T2 editted_obj) : action(act), obj(obj_), edittedObj(editted_obj) {}
	/*{
		action = act;
		obj = obj_;
	}*/
	Cancel(const Cancel& obj_) : edittedObj(obj_.edittedObj)
	{
		action = obj_.action;
		obj = obj_.obj;
		//edittedObj = obj_.edittedObj;
	}
	//void operator=(Cancel& obj);
	void cancelAction(Tree<T1>& tree);
};



//template<typename T1, typename T2>
//void Cancel<T1, T2>::operator=(Cancel & obj_)
//{
//	action = obj_.action;
//	obj = obj_.obj;
//	edittedObj = obj_.edittedObj;
//}

template<typename T1, typename T2>
void Cancel<T1, T2>::cancelAction(Tree<T1> & tree)
{
	if (action == "push") tree.pop(obj);
	else if (action == "pop") tree.push(obj);
	else edittedObj = obj; //при удалении объекта ссылка теряется, поэтому надо убрать ссылку
}


