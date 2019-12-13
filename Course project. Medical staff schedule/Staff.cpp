#include "pch.h"
#include "Staff.h"
#include "InputError.h"
#include <algorithm>
#include <fstream>

std::istream & operator>>(std::istream & in, Staff & obj)
{	
	obj.inputFullName(in);
	cout << "График дежурств:" << endl;
	obj.inputGraphic(in, obj.duty_graphic);
	cout << "График работы:" << endl;
	obj.inputGraphic(in, obj.work_graphic);
	return in;
}

std::ostream & operator<<(std::ostream & out, const Staff & obj)
{
	//вывод объекта в таблицу с разделителями и цветными границами
	obj.tableLines(out);
	using namespace std;
	
	out << setiosflags(ios::left) << color<12, 3> << '|' << color<> <<setw(14) << obj.firstName << color<12, 3> << '|' << color<>
		<< setw(19)  << obj.surname << color<12, 3> << '|' << color<> << setw(19) << obj.fatherName<< color<12, 3> << '|' << color<>;
	return out;
}

std::ifstream & operator>>(std::ifstream & in, Staff & obj)
{
	std::getline(in, obj.firstName, '|');
	std::getline(in, obj.surname, '|');
	std::getline(in, obj.fatherName, '|');

	graphic gr;
	obj.work_graphic.clear();
	obj.duty_graphic.clear();
	
	while (in.peek() != '|')
	{

		in >> gr.hour1 >> gr.hour2;
		char c=in.get();
		std::getline(in, gr.weekday, ' ');
		obj.work_graphic.push_back(gr);
	}
	in.get();
	while (in.peek() != '|')
	{
		in >> gr.hour1 >> gr.hour2;
		char c=in.get();
		std::getline(in, gr.weekday, ' ');
		obj.duty_graphic.push_back(gr);
	}
	in.get();
	return in;
}

std::ofstream & operator<<(std::ofstream & out, Staff & obj)
{
	out << obj.firstName << '|' << obj.surname << '|' << obj.fatherName << '|';
	list<graphic>::iterator it;
	for (it = obj.work_graphic.begin(); it != obj.work_graphic.end(); ++it)
		out << it->hour1 << ' ' << it->hour2 << ' ' << it->weekday << ' ';
	out << '|';
	for (it = obj.duty_graphic.begin(); it != obj.duty_graphic.end(); ++it)
		out << it->hour1<<' '<< it->hour2<<' ' << it->weekday << ' ';
	out << '|';
	return out;
}


void Staff::inputGraphic(std::istream & in, list<graphic>& list_graphic)
{
	int i;
	do
	{
		string day;
		graphic gr;
		day = inputWeekDay(in);
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
			inputHours(gr, in);
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
				out << std::setiosflags(std::ios::left) << setw(11) << time << color<12, 3> << '|' << color<>;
				break;
			}

		}
		
		if (fl) out << setw(11) << ' ' << color<12, 3> << '|' << color<>;
	}
}
	
void Staff::table(std::ostream & out)
{
	using namespace std;

	
	out << setiosflags(ios::left) << color<12, 3> << '|' << color<> << setw(14) << "Имя" << color<12, 3> << '|'<< color<> 
		<< setw(19) << "Фамилия" << color<12, 3> <<'|'<< color<> <<setw(19) << "Отчество";
	
}

void Staff::tableLines(std::ostream & out) const
{
	SetColor(12, 3);
	out << '+';
	string str1(14, '-');
	string str2(19, '-');
	out << str1 << '+' << str2 << '+' << str2 << '+';
	
}

void Staff::graphicLines(std::ostream & out)
{
	string str1(11, '-');
	out << str1 << '+' << str1 << '+' << str1 << '+' << str1 << '+' << str1 << '+' << str1 << '+' << str1 << '+';
	SetColor(14, 3);
	cout << endl;
}

void Staff::tableGraphic(std::ostream & out)
{
	cout << color<12, 3> <<'|'<< color<> <<setw(11) << "Понедельник" << color<12, 3> << '|' << color<> <<setw(11) << "Вторник" <<
		color<12, 3> << '|' << color<> << setw(11) << "Среда" << color<12, 3> << '|' << color<> << setw(11) << "Четверг" << 
		color<12, 3> << '|' << color<> << setw(11) << "Пятница" << color<12, 3> << '|' << color<> << setw(11) << "Суббота" <<
		color<12, 3> << '|' << color<> << setw(11) << "Воскресенье"<< color<12,3> <<'|'<<endl;
}

void Staff::chooseParameters()
{
	
	cout << "1-Имя" << endl;
	cout << "2-Фамилия" << endl;
	cout << "3-Отчество" << endl;
	cout << "4-День недели в графике дежурств" << endl;
	cout << "5-День недели в графике работы" << endl;
}

string Staff::getParameter(int n)
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
		gr.weekday = inputWeekDay();
		duty_graphic.push_back(gr);
		return "weekdayDuty";
	}
	case 5:
	{
		cout << "День недели в графике работы:";
		graphic gr;
		gr.weekday = inputWeekDay();
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
		day = inputWeekDay();
		editGraphic(day, 0);
		break;
	}
	case 5:
	{
		cout << "День недели в графике работы:";
		string day;
		day = inputWeekDay();
		editGraphic(day, 1);
		break;
	}
	}
}

void Staff::editGraphic(string day, bool listType)
{
	cout << "1-Отредактировать день\n" <<"2-Добавить день\n"<< "0-Удалить день" << endl;
	int operation;
	inputNumber(cin, operation, 0, 2);
	
	list<graphic> l;
	if (listType) l = work_graphic;
	else l = duty_graphic;

	list<graphic>::iterator it;
	for (it = l.begin(); it != l.end(); ++it)
	{
		if (operation && it->weekday == day)
		{
			if (operation == 2) {
				cout << "Данный день существует в графике дежурств. Для его изменения выполните операцию редактирования\n";
				break;
			}
			inputHours(*it);
			break;
		}
		else if (!operation && it->weekday == day)
		{
			l.erase(it);
			break;
		}
	}
	if (operation == 1 && it == l.end()) cout << "Данного дня не существует в графике. Для изменений выполните операцию добавления\n";
	if (operation == 2 && it == l.end())
	{
		graphic gr;
		gr.weekday = day;
		inputHours(gr);
		l.push_back(gr);
	}
	if (listType) work_graphic=l;
	else  duty_graphic=l;
}

void Staff::inputFullName(std::istream& in)
{
	rewind(stdin);
	cout << "Введите имя:";
	std::getline(in, firstName);
	rewind(stdin);
	cout << "Введите фамилию:";
	std::getline(in, surname);
	rewind(stdin);
	cout << "Введите отчество:";
	std::getline(in, fatherName);
}

void Staff::inputHours(graphic& gr, std::istream& in)
{
	cout << "Первый час=";
	inputNumber(in, gr.hour1, 0, 24);
	cout << "Последний час=";
	inputNumber(in, gr.hour2, gr.hour1, 24);
}

string Staff::inputWeekDay(std::istream & in)
{
	cout << "День недели:\n";
	cout << "1-Понедельник\n" << "2-Вторник\n" << "3-Среда\n" << "4-Четверг\n" << "5-Пятница\n" << "6-Суббота\n"
		<< "7-Воскресенье\n";
	int n;
	inputNumber(in, n, 1, 7);
	std::vector<string> vect{ "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
	return vect[n - 1];
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

void Staff::setSurname(string surname_)
{
	surname = surname_;
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
