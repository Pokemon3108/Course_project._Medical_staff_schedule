#pragma once
#include "Tree.h"
#include "pch.h"

template<typename T>
class Cancel
{
private:
	string action; //действие, которое осуществил пользователь
	T obj; //объект, с которым произвели операцию
	T edittedObj; //отредактированный объект (при выполнении пользователем операции редактирования)
public:
	Cancel() = default;
	~Cancel() {}
	Cancel(string act, T obj_, T editted_obj) : action(act), obj(obj_), edittedObj(editted_obj) {}
	Cancel(string act, T obj_) : action(act), obj(obj_) {}
	Cancel(const Cancel& obj_) : action(obj_.action), obj(obj_.obj), edittedObj(obj_.edittedObj) {}
	
	void cancelAction(Tree<T>& tree); //отмена последнего действия
};


template<typename T>
void Cancel<T>::cancelAction(Tree<T> & tree)
{
	if (action == "push") tree.pop(obj); //если последним действием было вставка, то удаляем объект из дерева
	else if (action == "pop") tree.push(obj); //если последним действием было удаление, то вставляем объект  в дерево
	else
	{
		Node<T>* temp = tree.search(edittedObj); //поиск узла, который хранит отредатированный объект
		temp->data = obj; //замена отредактированного объекта на объект до редактирования
	}
}


