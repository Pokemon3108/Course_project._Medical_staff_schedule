#include "pch.h"
#include "Nurse.h"


std::istream & operator>>(std::istream & in, Nurse & obj)
{
	in >> dynamic_cast<MedicalStaff&>(obj);
	cout << "ѕрофиль работы:";
	inputLetters(in, obj.workprofile);
	return in;
}

std::ostream & operator<<(std::ostream & out, const Nurse & obj)
{
	//вывод объекта в таблицу с разделител€ми и цветными границами
	using namespace std;
	out << dynamic_cast<const MedicalStaff&>(obj);
	out << setiosflags(ios::left) << setw(24) << obj.workprofile<< color<12, 3> << '|' << color<>;
	return out;
}

std::ifstream & operator>>(std::ifstream & in, Nurse & obj)
{
	in >> dynamic_cast<MedicalStaff&>(obj);
	std::getline(in, obj.workprofile, '\n');
	return in;
}

std::ofstream & operator<<(std::ofstream & out, Nurse & obj)
{
	out << dynamic_cast<MedicalStaff&>(obj);
	out << obj.workprofile << '\n';
	return out;
}

//bool Nurse::operator==(Nurse & obj)
//{
//	return (dynamic_cast<MedicalStaff&>(obj) == *(dynamic_cast<MedicalStaff*>(this))
//		&& obj.workprofile == workprofile);
//}

void Nurse::setWorkProfile(string profile)
{
	workprofile = profile;
}

string Nurse::getWorkProfile()
{
	return workprofile;
}

void Nurse::table(std::ostream & out)
{
	using namespace std;
	MedicalStaff::table(out);
	out << setiosflags(ios::left) << color<12, 3> << '|' << color<><<setw(24) << "ѕрофиль работы";
}

void Nurse::tableLines(std::ostream & out) const
{
	MedicalStaff::tableLines(out);
	string str(24, '-');
	out << str << '+';
	Nurse obj;
	obj.graphicLines(out);
}

void Nurse::chooseParameters()
{
	MedicalStaff::chooseParameters();
	cout << "7-ѕрофиль работы" << endl;
}

string Nurse::getParameter(int n)
{
	
	string parameter; //параметр, который определ€ет какое поле было выбрано дл€ поиска
	
	parameter = MedicalStaff::getParameter(n); //получаем выбранное поле родительского класса
	if (parameter == "") //если пол€ родительских классов не были выбраны, то работаем с пол€ми данного класса
	{
		switch (n)
		{
		case 7:
			std::cout << "ѕрофиль работы:";
			inputLettersAndNumbers(cin, workprofile);
			return "workProfile";
		}
	}
	//если был выбран параметр родительского класса, то вернуть его
	return parameter;
}

void Nurse::edit(int n)
{
	//определение параметра, который выбрал пользователь
	MedicalStaff::edit(n);
	if (n == 7)
	{
		//если пользователь выбрал 7-й параметр, то редактируем профиль работы
		std::cout << "ѕрофиль работы:";
		inputLetters(cin, workprofile);
	}
}
