#pragma once
#include "pch.h"
#include "Tree.h"

template<typename T>
class File
{
	const char* filename;
	std::ifstream in;
	std::ofstream out;
public:
	File()=default;
	~File()
	{
		in.close();
		out.close();
	}

	//void openForWrite(const char* name);
	//void openForRead(const char* name);
	void readFromFile(Tree<T>& tree);
	void writeToFile(Node<T>* root);
	std::ifstream& getIn();
	std::ofstream& getOut();
	
	
};

//template<typename T>
//void File<T>::openForWrite(const char * name)
//{
//	out.open(name);
//	if (!out.is_open())
//		cerr << "Невозможно открыть файл для записи" << endl;
//}
//
//template<typename T>
//void File<T>::openForRead(const char * name)
//{
//	in.open(name);
//	if (!in.is_open())
//		cerr << "Невозможно открыть файл для чтения" << endl;
//}

template<typename T>
void File<T>::readFromFile(Tree<T>& tree)
{
	T obj;
	while (in.peek() == '\n')
		in.get();
	while (!in.eof())
	{
		in >> obj;
		tree.push(obj);
		in.peek();
	}
}

template<typename T>
void File<T>::writeToFile(Node<T>* root)
{
	if (!root) return;
	out << root->data;
	writeToFile(root->left);
	writeToFile(root->right);
}

template<typename T>
std::ifstream & File<T>::getIn()
{
	return in;
}

template<typename T>
std::ofstream & File<T>::getOut()
{
	return out;
}

