#pragma once
#include "pch.h"
#include "InputError.h"
#include <vector>
#include "Colour.h"

struct graphic
{
	int hour1; //первый час работы/дежурства
	int hour2; //последний час работы/дежурства
	string weekday; //день недели в графике работы/дежурств
};

class Staff abstract
{
protected:
	string firstName; //имя работника
	string surname; //фамилия работника
	string fatherName; //отчество работника
	list<graphic> work_graphic; //график работы
	list<graphic> duty_graphic; //график дежурств
public:
	Staff() = default;
	Staff(string firstName, string surname_, string fatherName, list<graphic> work, list<graphic> duty) :
		firstName(firstName), surname(surname_), fatherName(fatherName), work_graphic(work), duty_graphic(duty) {}
	Staff(const Staff& obj) : firstName(obj.firstName), surname(obj.surname), fatherName(obj.fatherName),
		work_graphic(obj.work_graphic), duty_graphic(obj.duty_graphic) {}
	~Staff() {}

	friend std::istream& operator >> (std::istream& in, Staff& obj); //инициализация объекта класса Staff с консоли
	friend std::ostream& operator << (std::ostream& out, const Staff& obj); //вывод объекта класса Staff на экран
	friend std::ifstream& operator >>(std::ifstream& in, Staff& obj); //чтение объекта класса Staff из файла
	friend std::ofstream& operator << (std::ofstream& out, Staff& obj); //запись объекта класса ServiceStaff в файл

	void inputGraphic(std::istream& in, list<graphic>& list_graphic); //инициализация графика работы/дежурств
	virtual void table(std::ostream & out);  //вывод шапки таблицы
	virtual void tableLines(std::ostream& out) const; // вывод линий-разделителей в таблице
	virtual void graphicLines(std::ostream& out); //вывод линий-разделителей для графика в таблице
	void tableGraphic(std::ostream & out); //вывод шапки графика
	void outputGraphic(std::ostream & out, bool flag); //вывод графика
	

	virtual void chooseParameters(); //меню для выбора параметра для поиска/редактирования
	virtual string getParameter(int n); //возвращает строку с названием поля, которое подлежит редатированию

	virtual void edit(int n); //редактирование выбранного поля в объекте класса Staff
	void editGraphic(string day, bool listType); //редактирование графика
	
	void inputFullName(std::istream& in=cin); //инициализация полного имени работника
	void inputHours(graphic& gr, std::istream& in = cin); //инициализация часов в графике
	string inputWeekDay(std::istream& in = cin); //возвращает введённый день недели

	bool operator !=(Staff& obj); //проверка на равенство полных имён работников
	bool operator >(Staff& obj); //сравнение полных имён работников
	bool operator <(Staff& obj); //сравнение полных имён работников
	bool operator ==(Staff& obj); //проверка на равенство полных имён работников
	
	string getFirstName() const; //возвращает имя работника
	void setFirstName(string name); //устанавливает имя работника
	
	string getSurname() const; //возвращает фамилию работника
	void setSurname(string surname_); //устанавливает фамилию работника
	
	string getFatherName() const; //возвращает отчество работника
	void setFatherName(string fatherName_); //устанавливает отчество работника
	
	int getHour1(string day, list<graphic>& gr) const; //возвращает первый час в определённом дне из графике
	void setHour1(string day, int hour, list<graphic>& gr); //устанавливает первый час в определённом дне из графике
	
	int getHour2(string day, list<graphic>& gr) const; //возвращает второй час в определённом дне из графике
	void setHour2(string day, int hour, list<graphic>& gr); //устанавливает второй час в определённом дне из графике

	list<graphic>& getDutyGraphic(); //возвращает график дежурств
	list<graphic>& getWorkGraphic(); //возвращает график работы

	bool daysInGraphic(list<graphic>& objInTree, list<graphic>& objSearch); //определяет, входит ли objSearch в objInTree
};

