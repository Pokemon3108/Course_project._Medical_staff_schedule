#include "pch.h"
#include "Doctor.h"

std::istream & operator>>(std::istream & in, Doctor & obj)
{
	in >> dynamic_cast<MedicalStaff&>(obj);
	cout << "Категория:";
	inputLettersAndNumbers(in, obj.category);
	cout << "Специальность:";
	inputLetters(in, obj.speciality);
	return in;
}

std::ostream & operator<<(std::ostream & out, const Doctor & obj)
{
	//вывод объекта в таблицу с разделителями и цветными границами
	using namespace std;
	out << dynamic_cast<const MedicalStaff&>(obj);
	out << setiosflags(ios::left) << setw(10) << obj.category<< color<12, 3> << '|' << color<> << setw(10) 
		<<setw(19) << obj.speciality << color<12, 3> << '|' << color<>; 
	return out;
}

std::ifstream & operator>>(std::ifstream & in, Doctor & obj)
{
	in >> dynamic_cast<MedicalStaff&>(obj);
	std::getline(in, obj.category, '|');
	std::getline(in, obj.speciality, '\n');
	return in;
}

std::ofstream & operator<<(std::ofstream & out, Doctor & obj)
{
	out << dynamic_cast<MedicalStaff&>(obj);
	out << obj.category << '|' << obj.speciality << '\n';
	return out;

}

//bool Doctor::operator==(Doctor & obj)
//{
//	return (dynamic_cast<MedicalStaff&>(obj) == *(dynamic_cast<MedicalStaff*>(this)) && obj.category==category
//		&& obj.speciality==speciality);
//}

string Doctor::getCategory()
{
	return category;
}

void Doctor::setCategory(string category_)
{
	category = category_;
}

string Doctor::getSpeciality()
{
	return speciality;
}

void Doctor::setSpeciality(string speciality_)
{
	speciality = speciality_;
}

void Doctor::table(std::ostream & out)
{
	using namespace std;
	MedicalStaff::table(out);

	//вывод шапки таблицы с изменением цвета линий-разделителей между названиями колонок
	out << setiosflags(ios::left) << color<12, 3> << '|' << color<> << setw(10) << "Категория" << 
		color<12, 3> << '|' << color<> << setw(19) << "Специальность"; 
}

void Doctor::tableLines(std::ostream & out) const
{
	//вывод линий-разделителей между строками таблицы
	MedicalStaff::tableLines(out);
	string str1(10, '-');
	string str2(19, '-');
	out << str1 << '+' << str2 << '+';
	
	Doctor obj;
	obj.graphicLines(out); //вывод линий-разделителей между строкми таблицы для колонок с графиком
	
}

void Doctor::chooseParameters()
{
	MedicalStaff::chooseParameters();
	cout << "7-Категория" << endl;
	cout << "8-Специальность" << endl;
}

string Doctor::getParameter(int n)
{
	
	string parameter; //параметр, который определяет какое поле было выбрано для поиска
	
		parameter = MedicalStaff::getParameter(n); //получаем выбранное поле родительского класса
		if (parameter == "") //если поля родительских классов не были выбраны, то работаем с полями данного класса
		{
			switch (n)
			{
			case 7: //если пользователь выбрал 7 - й параметр, то вводим категорию и возвращаем название поля
				std::cout << "Категория:";
				inputLettersAndNumbers(cin, category);
				return "category";
			case 8: //если пользователь выбрал 7 - й параметр, то вводим специальность и возвращаем название поля
				std::cout << "Специальность:" << endl;
				inputLetters(cin, speciality);
				return "speciality";
			}
		}

	return parameter;
}

void Doctor::edit(int n)
{
	//определение параметра, который выбрал пользователь
	MedicalStaff::edit(n);
	switch (n)
	{
	case 7: //если пользователь выбрал 7-й параметр, то редактируем категорию
		std::cout << "Категория:";
		inputLettersAndNumbers(cin, category);
		break;
	case 8: //если пользователь выбрал 8-й параметр, то редактируем специальность
		std::cout << "Специальность:" << endl;
		inputLetters(cin, speciality);
		break;
	}
}
