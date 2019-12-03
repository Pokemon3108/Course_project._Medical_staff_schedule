#include "pch.h"
#include "Staff.h"
#include "InputError.h"
#include <algorithm>
#include <fstream>

std::istream & operator>>(std::istream & in, Staff & obj)
{	
	cout << "Имя: ";
	inputLetters(in, obj.firstName);
	cout << "Фамилия: ";
	inputLetters(in, obj.surname);
	cout << "Отчество: ";
	inputLetters(in, obj.fatherName);
	cout << "График дежурств:" << endl;
	obj.inputGraphic(in, obj.duty_graphic);
	cout << "График работы:" << endl;
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

std::ifstream & operator>>(std::ifstream & in, Staff & obj)
{
	std::getline(in, obj.firstName, '\n');
	std::getline(in, obj.surname, '\n');
	std::getline(in, obj.fatherName, '\n');
	int size;
	in >> size;
	graphic gr;
	for (; size; --size)
	{
		in >> gr.hour1 >> gr.hour2;
		in.get();
		std::getline(in, gr.weekday, '\n');
		obj.work_graphic.push_back(gr);
	}
	in >> size;
	for (; size; --size)
	{
		in >> gr.hour1 >> gr.hour2;
		in.get();
		std::getline(in, gr.weekday, '\n');
		obj.duty_graphic.push_back(gr);
	}

	return in;
}

std::ofstream & operator<<(std::ofstream & out, Staff & obj)
{
	out << obj.firstName << '\n' << obj.surname << '\n' << obj.fatherName << '\n';
	list<graphic>::iterator it;
	int size = obj.work_graphic.size();
	out << size << '\n';
	for (it = obj.work_graphic.begin(); it != obj.work_graphic.end(); ++it)
		out << it->hour1 << '\n' << it->hour2 << '\n' << it->weekday << '\n';
	
	size = obj.duty_graphic.size();
	out << size << '\n';
	for (it = obj.duty_graphic.begin(); it != obj.duty_graphic.end(); ++it)
		out << it->hour1<<'\n'<< it->hour2<<'\n' << it->weekday << '\n';
	
	return out;
}


void Staff::inputGraphic(std::istream & in, list<graphic>& list_graphic)
{
	int i;
	do
	{
		string day;
		graphic gr;
		cout << "День недели:";
		inputWeekDay(in, day);
		list<graphic>::iterator it=list_graphic.begin();
		while (it != list_graphic.end())
		{
			if ((*it).weekday == day)
			{
				cout << "\nДанный день недели уже существует в графике. Для изменения выполните операцию редактирования\n";
				break;
			}
			it++;
		}
		if (it==list_graphic.end())
		{
			gr.weekday = day;
			cout << "Первый час=";
			inputNumber(in, gr.hour1, 0, 24);
			cout << "Последний час=";
			inputNumber(in, gr.hour2, gr.hour1, 24);
			list_graphic.push_back(gr);
		}
		

	cout << "1-Ввести еще один день графика"<<endl<< "0-Закончить ввод графика"<<endl;
	inputNumber(cin,i,0,1);

	} while (i);
}

void Staff::outputGraphic(std::ostream & out, bool flag)
{
	list<graphic> list_graphic;
	if (!flag) list_graphic = this->duty_graphic;
	else list_graphic = this->work_graphic;
	bool fl;
	list<graphic>::iterator it1, it2;
	int i = 1;
	for (; i<8; ++i)
	{
		fl = 1;
		for (it2 = list_graphic.begin(); it2 != list_graphic.end(); ++it2)
		{
			string time = std::to_string(it2->hour1) + "-" + std::to_string(it2->hour2);
			
			if ((it2->weekday == "Понедельник" && i == 1) || (it2->weekday == "Вторник" && i == 2) || 
				(it2->weekday == "Среда" && i == 3) || (it2->weekday == "Четверг" && i == 4) ||
				(it2->weekday == "Пятница" && i == 5) || (it2->weekday == "Суббота" && i == 6) || 
				(it2->weekday == "Воскресенье" && i == 7))
			{
				fl = 0;
				out << std::setiosflags(std::ios::left) << setw(11) << time << '|';
				break;
			}

		}
		
		if (fl) out << setw(11) << ' ' << '|';
	}
}
	
void Staff::table(std::ostream & out)
{
	using namespace std;
	out << setiosflags(ios::left) << setw(15) << "|Имя" << setw(20) << "|Фамилия" << setw(20) << "|Отчество";
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
	cout << setw(12) << "|Понедельник" << setw(12) << "|Вторник" << setw(12) << "|Среда" << setw(12) << "|Четверг" << setw(12)
		<< "|Пятница" << setw(12) << "|Суббота" << setw(12) << "|Воскресенье"<<'|'<<endl;
}

void Staff::chooseParameters()
{
	
	cout << "1-Имя" << endl;
	cout << "2-Фамилия" << endl;
	cout << "3-Отчество" << endl;
	cout << "4-День недели в графике дежурств" << endl;
	cout << "5-День недели в графике работы" << endl;
}

std::string Staff::getParameter(int n)
{
	switch (n)
	{
	case 1:
		cout << "Имя:";
		inputLetters(cin, firstName);
		return "firstName";
	case 2:
		cout << "Фамилия:";
		inputLetters(cin, surname);
		return "surname";
	case 3:
		cout << "Отчество:";
		inputLetters(cin, fatherName);
		return "fatherName";
	case 4:
	{
		cout << "День недели в графике дежурств:";
		graphic gr;
		inputLetters(cin, gr.weekday);
		duty_graphic.push_back(gr);
		return "weekdayDuty";
	}
	case 5:
	{
		cout << "День недели в графике работы:";
		graphic gr;
		inputLetters(cin, gr.weekday);
		work_graphic.push_back(gr);
		return "weekdayWork";
	}
	default:
		return "";
	}
}

void Staff::edit(int n)
{
	switch (n)
	{
	case 1:
		cout << "Имя:";
		inputLetters(cin, firstName); 
		break;
	case 2:
		cout << "Фамилия:";
		inputLetters(cin, surname);
		break;

	case 3:
		cout << "Отчество:";
		inputLetters(cin, fatherName);
		break;

	case 4:
	{
		cout << "День недели в графике дежурств:";
		string day;
		inputLetters(cin, day);
		editGraphic(day, 0);
		break;
	}
	case 5:
	{
		cout << "День недели в графике работы:";
		string day;
		inputLetters(cin, day);
		editGraphic(day, 1);
		break;
	}
	}
}

void Staff::editGraphic(string day, int listType)
{
	cout << "1-Отредактировать день" << endl << "0-Удалить день" << endl;
	int operation;
	inputNumber(cin, operation, 0, 1);
	
	list<graphic> l;
	if (listType) l = work_graphic;
	else l = duty_graphic;
	list<graphic>::iterator it;
	for (it = l.begin(); it != l.end(); ++it)
	{
		if (operation && it->weekday == day)
		{
			cout << "Первый час=";
			inputNumber(cin, it->hour1, 0, 24);
			cout << "Последний час=";
			inputNumber(cin, it->hour2, it->hour1, 24);
			break;
		}
		else if (!operation && it->weekday == day)
		{
			l.erase(it);
			break;
		}
	}
	if (listType) work_graphic=l;
	else  duty_graphic=l;
}

void Staff::inputFullName()
{
	rewind(stdin);
	cout << "Введите имя:";
	std::getline(cin, firstName);
	rewind(stdin);
	cout << "Введите фамилию:";
	std::getline(cin, surname);
	rewind(stdin);
	cout << "Введите отчество:";
	std::getline(cin, fatherName);
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
