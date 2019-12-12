#pragma once
#include "pch.h"

template <typename T>
struct Node
{
	T data; //информация, хранящаяся в узле
	Node<T> *left; //указатель на левый узел 
	Node<T> *right; //указатель на правый узел
	Node<T> *parent; //указатель на родительский узел
};


template <typename T>
class Tree
{
private:

	Node<T> *root; //указатель на корень дерева

public:

	class Iterator
	{
	private:
		Node<T>* ptr; //указатель на текущий узел дерева
		
	public:
		Iterator() : ptr(nullptr) {};

		T& operator*(); //возвращает ссылку на объект, хранящийся в ptr

		Iterator operator++(int); //переход на следующий по возрастанию
		Iterator operator--(int); //переход на следующий по убыванию
		Iterator operator+=(int n); //переход на n узлов по возрастанию

		bool operator==(Iterator it); //сравнение указателей
		bool operator!=(Iterator it); //сравнение указателей

		Node<T>* getPtr()
		{
			return ptr;
		}

		friend class Tree;
	};


	Tree()
	{
		root = nullptr;
	}
	~Tree()
	{
		destroyTree(root);
	}
	Tree(T obj)
	{
		root->data = obj;
		root->left = nullptr;
		root->right = nullptr;
		root->parent = nullptr;
	}

	void push(T obj); //вызывает рекурсивный метод вставки insert
	void insert(Node<T>* &root, T data, Node<T>* parent); //вставляет data в дерево

	Node<T> * search(T & obj) const; //поиск объекта в дереве

	void show(bool flag); //вывод информации, хранящейся в дереве

	//рекурсивный метод поиска узла для удаления
	//при нахождении переход к методу deleteNewRootItem, куда в параметр передаётся данный узел
	//то есть в deleteNewRootItem он является корнем
	void deleteItem(Node<T>* &ptr, T data); 

	void deleteNewRootItem(Node<T>*& nodeptr); //удаление корня поддерева
	void mostLeftItem(Node<T>* &nodeptr, T& value); //удаление самого левого узела
	
	void pop(T obj); //вызывает рекурсивный метод удаления deleteItem

	void destroyTree(Node<T>* &root); //удаляет дерево полностью

	Node<T>*& getRoot(); //возвращает корень дерева

	Iterator begin(); //возвращает объекта класса Iterator на самый левый узел
	Iterator end(); //возвращает объекта класса Iterator на самый правый узел

	
};

template<typename T>
void Tree<T>::push(T obj)
{
	insert(root, obj, nullptr);
}

template<typename T>
void Tree<T>::insert(Node<T>* &root, T data, Node<T>* parent)
{
	Node<T>* temp = root;
	if (!root)
	{
		root = new Node<T>;
		root->data = data;
		root->left = nullptr;
		root->right = nullptr;
		root->parent = parent;
	}
	else if (data < root->data)
		insert(root->left, data, root);
	else if (data > root->data)
		insert(root->right, data, root);

}


template<typename T>
Node<T>* Tree<T>::search(T & obj) const
{
	if (!root) return nullptr;
	Node<T>* temp = root;
	while (temp && temp->data != obj)
	{
		if (obj < temp->data)
			temp = temp->left;

		else if (obj > temp->data)
			temp = temp->right;

	}
	return temp;
}


template<typename T>
void Tree<T>::show(bool flag)
{
	Iterator it;
	for (it = begin(); it != end(); it++)
	{
		cout << *it;
		(*it).outputGraphic(cout,flag);
		cout <<  endl;
	}
}

template <typename T>
void Tree<T>::pop(T obj)
{
	deleteItem(root, obj);
}

template <typename T>
void Tree<T>::deleteItem(Node<T> * &ptr, T data)
{
	if (!ptr) return;
	else if (data == ptr->data)
		deleteNewRootItem(ptr);
	else if (data < ptr->data)
		deleteItem(ptr->left, data);
	else deleteItem(ptr->right, data);
}

template <typename T>
void Tree<T>::deleteNewRootItem(Node<T> * &nodeptr)
{
	Node<T>*delptr;
	T value;
	if (!nodeptr->left && !nodeptr->right)
	{
		delete nodeptr;
		nodeptr = nullptr;
	}
	else if (!nodeptr->left || !nodeptr->right)
	{
		delptr = nodeptr;
		if (!nodeptr->left) nodeptr = nodeptr->right;
		else nodeptr = nodeptr->left;
		nodeptr->parent = delptr->parent;
		delete delptr;
	}
	else
	{
		mostLeftItem(nodeptr->right, value);
		nodeptr->data = value;
	}
}

template <typename T>
void Tree<T>::mostLeftItem(Node<T> * &nodeptr, T& value)
{
	if (!nodeptr->left)
	{
		value = nodeptr->data;
		Node<T>* delptr = nodeptr;
		nodeptr = nodeptr->right;
		if (nodeptr) nodeptr->parent = delptr->parent;
		delete delptr;

	}
	else mostLeftItem(nodeptr->left, value);
	
}


template <typename T>
void Tree<T>::destroyTree(Node<T>*&root)
{
	if (root)
	{

		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
		root = nullptr;
	}
}

template<typename T>
Node<T>*& Tree<T>::getRoot()
{
	return root;
}

template<typename T>
typename Tree<T>::Iterator Tree<T>::begin()
{
	
	Iterator it;
	if (!root) return it;
	
	Node<T>*curr = root;
	
	while (curr->left)
	curr = curr->left;

	it.ptr = curr;
	return it;

}
template<typename T>
typename Tree<T>::Iterator Tree<T>::end()
{
	Iterator it;
	if (!root) return it;
	Node<T>*curr = root;

	while (curr)
		curr = curr->right;

	it.ptr = curr;
	return it;
}


template<typename T>
T& Tree<T>::Iterator::operator*()
{
	return this->ptr->data;
}

template<typename T>
typename Tree<T>::Iterator Tree<T>::Iterator::operator++(int)
{
	Node<T>* temp;
	if (ptr->right)
	{
		ptr = ptr->right;
		while (ptr->left)
			ptr = ptr->left;
	}
	else
	{
		temp = ptr->parent;
		while (temp && ptr == temp->right)
		{
			ptr = temp;
			temp = temp->parent;
		}
		ptr = temp;
	}
	return *this;
}

template<typename T>
typename Tree<T>::Iterator Tree<T>::Iterator::operator--(int)
{
	Node<T>* temp;
	if (ptr->left)
	{
		ptr = ptr->left;
		while (ptr->right)
			ptr = ptr->right;
	}
	else
	{
		temp = ptr->parent;
		while (temp && ptr == temp->left)
		{
			ptr = temp;
			temp = temp->parent;
		}
		ptr = temp;
	}
	return *this;

}

template<typename T>
bool Tree<T>::Iterator::operator==(Iterator it)
{
	if (it.ptr == nullptr && this->ptr == nullptr) return true;
	if (it.ptr == nullptr || this->ptr == nullptr) return false;
	return **this == *it;
}

template<typename T>
bool Tree<T>::Iterator::operator!=(Iterator it)
{
	return !(*this == it);
}

template<typename T>
typename Tree<T>::Iterator Tree<T>::Iterator::operator+=(int n)
{
	for (int i = 0; i < n; ++i)
		(*this)++;
	return *this;
}
