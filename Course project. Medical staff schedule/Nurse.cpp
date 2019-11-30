#include "pch.h"
#include "Nurse.h"


std::istream & operator>>(std::istream & in, Nurse & obj)
{
	in >> dynamic_cast<MedicalStaff&>(obj);
	cout << "Должность:";
	inputLetters(in, obj.workprofile);
	return in;
}

std::ostream & operator<<(std::ostream & out, const Nurse & obj)
{
	using namespace std;
	out << dynamic_cast<const MedicalStaff&>(obj);
	out << setiosflags(ios::left) << setw(19) << obj.workprofile<<'|';
	return out;
}

bool Nurse::operator==(Nurse & obj)
{
	return (dynamic_cast<MedicalStaff&>(obj) == *(dynamic_cast<MedicalStaff*>(this))
		&& obj.workprofile == workprofile);
}

bool Nurse::operator!=(Nurse & obj)
{
	return (!(*this == obj));
}

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
	out << setiosflags(ios::left) << setw(20) << "|Профиль работы";
}

void Nurse::tableLines(std::ostream & out) const
{
	MedicalStaff::tableLines(out);
	string str(19, '-');
	out << str << '+';
	Nurse obj;
	obj.graphicLines(out);
}

void Nurse::chooseParameters()
{
	MedicalStaff::chooseParameters();
	cout << "7-Профиль работы" << endl;
}

string Nurse::getParameter(int n)
{
	int i = 0;
	string parameter;
	do
	{
		parameter = MedicalStaff::getParameter(n);
		if (parameter == "")
		{
			switch (n)
			{
			case 7:
				std::cout << "Профиль работы:";
				inputLettersAndNumbers(cin, workprofile);
				return "workProfile";

			default:
				i = 1;
			}
		}
	} while (i);
	return parameter;
}