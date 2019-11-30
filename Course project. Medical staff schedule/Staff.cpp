#include "pch.h"
#include "Staff.h"
#include "InputError.h"
#include <algorithm>

std::istream & operator>>(std::istream & in, Staff & obj)
{
	cout << "���: ";
	inputLetters(in, obj.firstName);
	cout << "�������: ";
	inputLetters(in, obj.surname);
	cout << "��������: ";
	inputLetters(in, obj.fatherName);
	cout << "������ ��������:" << endl;
	obj.inputGraphic(in, obj.duty_graphic);
	cout << "������ ������:" << endl;
	obj.inputGraphic(in, obj.work_graphic);
	return in;
}

std::ostream & operator<<(std::ostream & out, const Staff & obj)
{
	obj.tableLines(out);
	using namespace std;
	out << setiosflags(ios::left) << '|'<<setw(14) << obj.firstName <<'|'<< setw(19)  << obj.surname <<'|'<< setw(19) 
		<< obj.fatherName<<'|';
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
			{
				cout << "\n������ ���� ������ ��� ���������� � �������. ��� ��������� ��������� �������� ��������������\n";
				it = list_graphic.end();
			}
			it++;
		}
		if (it==list_graphic.end())
		{
			gr.weekday = day;
			cout << "������ ���=";
			inputNumber(in, gr.hour1, 0, 24);
			cout << "��������� ���=";
			inputNumber(in, gr.hour2, 0, 24);
			list_graphic.push_back(gr);
		}
		

	cout << "1-������ ��� ���� ���� �������"<<endl<< "0-��������� ���� �������"<<endl;
	in >> i;

	} while (i);
}

void Staff::outputGraphic(std::ostream & out, bool flag)
{
	list<graphic> list_graphic;
	if (!flag) list_graphic = this->duty_graphic;
	else list_graphic = this->work_graphic;
	bool f;
	list<graphic>::iterator it1, it2;
	int i = 1;
	for (; i<8; ++i)
	{
		f = 1;
		for (it2 = list_graphic.begin(); it2 != list_graphic.end(); ++it2)
		{
			string time = std::to_string(it2->hour1) + "-" + std::to_string(it2->hour2);
			
			if ((it2->weekday == "�����������" && i == 1) || (it2->weekday == "�������" && i == 2) || 
				(it2->weekday == "�����" && i == 3) || (it2->weekday == "�������" && i == 4) ||
				(it2->weekday == "�������" && i == 5) || (it2->weekday == "�������" && i == 6) || 
				(it2->weekday == "�����������" && i == 7))
			{
				f = 0;
				out << std::setiosflags(std::ios::left) << setw(11) << time << '|';
				break;
			}

		}
		
		if (f) out << setw(11) << ' ' << '|';
	}
}
	
void Staff::table(std::ostream & out)
{
	using namespace std;
	out << setiosflags(ios::left) << setw(15) << "|���" << setw(20) << "|�������" << setw(20) << "|��������";
}

void Staff::tableLines(std::ostream & out) const
{
	out << '+';
	string str1(14, '-');
	string str2(19, '-');
	out << str1 << '+' << str2 << '+' << str2 << '+';
}

void Staff::graphicLines(std::ostream & out)
{
	string str1(11, '-');
	out << str1 << '+' << str1 << '+' << str1 << '+' << str1 << '+' << str1 << '+' << str1 << '+' << str1 << '+' << endl;
}

void Staff::tableGraphic(std::ostream & out)
{
	cout << setw(12) << "|�����������" << setw(12) << "|�������" << setw(12) << "|�����" << setw(12) << "|�������" << setw(12)
		<< "|�������" << setw(12) << "|�������" << setw(12) << "|�����������"<<'|'<<endl;
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

list<graphic>& Staff::getDutyGraphic()
{
	return this->duty_graphic;
}

list<graphic>& Staff::getWorkGraphic()
{
	return this->work_graphic;
}

bool Staff::daysInGraphic(list<graphic>& objInTree, list<graphic>& objSearch)
{
	list<graphic>::iterator it1, it2;
	for (it1 = objSearch.begin(); it1 != objSearch.end(); ++it1)
	{
		for (it2 = objInTree.begin(); it2 != objInTree.end(); ++it2)
		{
			if (it1->weekday == it2->weekday) break;
			if (it2 == objInTree.end()) return false;
		}
	}
	return true;
}
