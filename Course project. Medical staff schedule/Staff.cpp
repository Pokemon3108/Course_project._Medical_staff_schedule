#include "pch.h"
#include "Staff.h"
#include "InputError.h"
#include <algorithm>

std::istream & operator>>(std::istream & in, Staff & obj)
{
	cout << "���:";
	inputLetters(in, obj.firstName);
	cout << "�������:";
	inputLetters(in, obj.surname);
	cout << "��������";
	inputLetters(in, obj.fatherName);
	cout << "������ ��������" << endl;
	obj.inputGraphic(in, obj.duty_graphic);
	cout << "������ ������:" << endl;
	obj.inputGraphic(in, obj.work_graphic);
	return in;
}

std::ostream & operator<<(std::ostream & out, const Staff & obj)
{
	using namespace std;
	out << setiosflags(ios::left) << setw(15) << obj.firstName << setw(20) << obj.surname << setw(20) << obj.fatherName;
	return out;
}


void Staff::inputGraphic(std::istream & in, list<graphic>& list_graphic)
{
	int i;
	do
	{
		string day;
		graphic gr;
		cout << "���� ������:";
		inputLetters(in, day);
		list<graphic>::iterator it=list_graphic.begin();
		while (it != list_graphic.end())
		{
			if ((*it).weekday == day)
				cout << "\n������ ���� ������ ��� ���������� � �������. ��� ��������� ��������� �������� ��������������\n";
			it++;;
		}
		cout << "������ ���=";
		inputNumber(in, gr.hour1, 0, 24);
		cout << "��������� ���=";
		inputNumber(in, gr.hour2, 0, 24);
		

		list_graphic.push_back(gr);

		cout << "1-������ ��� ���� ���� �������";
		cout << "0-��������� ���� �������";
		cin >> i;

	} while (i);
}

//void Staff::outputGraphic(std::istream & in, list<graphic>& list_graphic)
//{
//	list<graphic>::iterator it;
//	int i=0;
//	for (it = list_graphic.begin(); it != list_graphic.end(); it++, i++)
//	{
//		if ((*it).weekday == "�����������" && i==0) 
//		{
//			cout << setw(13) << (*it).hour1 - (*it).hour2;
//			continue;
//		}
//
//	}
//}
	

void Staff::table(std::ostream & out)
{
	using namespace std;
	out << setiosflags(ios::left) << setw(15) << "���" << setw(20) << "�������" << setw(20) << "��������";
}

void Staff::tableGraphic(std::ostream & out)
{
	cout << setw(13) << "�����������" << setw(9) << "�������" << setw(6) << "�����" << setw(9) << "�������" << setw(9)
		<< "�������" << setw(9) << "�������" << setw(13) << "�����������\n";
}

void Staff::chooseParameters()
{
	cout << "�������� ��������� ��� ������:" << endl;
	cout << "1-���" << endl;
	cout << "2-�������" << endl;
	cout << "3-��������" << endl;
	cout << "4-���� ������ � ������� ��������" << endl;
	cout << "5-���� ������ � ������� ������" << endl;
}

std::string Staff::getParameter(int n)
{
	switch (n)
	{
	case 1:
		cout << "���:";
		inputLetters(cin, firstName);
		return "firstName";
	case 2:
		cout << "�������:";
		inputLetters(cin, surname);
		return "surname";
	case 3:
		cout << "��������:";
		inputLetters(cin, fatherName);
		return "fatherName";
	case 4:
	{
		cout << "���� ������ � ������� ��������:";
		graphic gr;
		inputLetters(cin, gr.weekday);
		duty_graphic.push_back(gr);
		return "weekdayDuty";
	}
	case 5:
	{
		cout << "���� ������ � ������� ������:";
		graphic gr;
		inputLetters(cin, gr.weekday);
		work_graphic.push_back(gr);
		return "weekdayWork";
	}
	default:
		return "";
	}
}

bool Staff::operator!=(Staff & obj)
{
	return (!(*this == obj));
}

bool Staff::operator>(Staff & obj)
{
	if (surname != obj.surname)
		return (surname > obj.surname);
	else if (firstName != obj.surname)
		return (firstName > obj.firstName);
	else return fatherName > obj.fatherName;

}

bool Staff::operator<(Staff & obj)
{
	return (!(*this > obj));
}

bool Staff::operator==(Staff & obj)
{
	return (firstName == obj.firstName && surname == obj.surname && fatherName == obj.fatherName );
}

string Staff::getFirstName() const
{
	return firstName;
}

void Staff::setFirstName(string name)
{
	firstName = name;
}

string Staff::getSurname() const
{
	return surname;
}

void Staff::setSurname(string sur)
{
	surname = sur;
}

string Staff::getFatherName() const
{
	return fatherName;
}

void Staff::setFatherName(string fatherName_)
{
	fatherName = fatherName_;
}

int Staff::getHour1(string day, list<graphic>& gr) const
{
	list<graphic>::iterator iter = gr.begin();
	for (; iter != gr.end(); iter++)
		if (iter->weekday == day) return iter->hour1;
	return -1;
}

void Staff::setHour1(string day, int hour, list<graphic>& gr)
{
	list<graphic>::iterator iter = gr.begin();
	for (; iter != gr.end(); iter++)
		if (iter->weekday == day) iter->hour1 = hour;
}

int Staff::getHour2(string day, list<graphic>& gr) const
{
	list<graphic>::iterator iter = gr.begin();
	for (; iter != gr.end(); iter++)
		if (iter->weekday == day) return iter->hour2;
	return -1;
}

void Staff::setHour2(string day, int hour, list<graphic>& gr)
{
	list<graphic>::iterator iter = gr.begin();
	for (; iter != gr.end(); iter++)
		if (iter->weekday == day) iter->hour2 = hour;
	
}