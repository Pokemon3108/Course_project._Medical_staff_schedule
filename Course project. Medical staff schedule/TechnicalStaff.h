#pragma once
#include "Staff.h"

class TechnicalStaff abstract : public Staff
{
protected:
	string profession;
public:
	TechnicalStaff() = default;
	TechnicalStaff(string profession_, string firstName_, string surname_, string fatherName_, 
		list<graphic> work, list<graphic> duty) :
		profession(profession_), Staff(firstName_, surname_, fatherName_, work, duty) {}
	TechnicalStaff(const TechnicalStaff& obj) :
		Staff(obj.firstName, obj.surname, obj.fatherName, obj.work_graphic, obj.duty_graphic), profession(obj.profession) {}

	~TechnicalStaff() {};

	void chooseParameters(); //меню для выбора параметра для поиска/редактирования
	string getParameter(int n); //возвращает строку с названием поля, которое подлежит редатированию

	virtual void table(std::ostream & out) override; //вывод шапки таблицы
	virtual void tableLines(std::ostream& out) const override; //вывод линий-разделителей в таблице

	friend std::istream& operator >> (std::istream& in, TechnicalStaff& obj); //инициализация объекта класса TechnicalStaff с консоли
	friend std::ostream& operator << (std::ostream& out, const TechnicalStaff& obj); //вывод объекта класса TechnicalStaff на экран
	friend std::ifstream& operator >>(std::ifstream& in, TechnicalStaff& obj); //чтение объекта класса TechnicalStaff из файла
	friend std::ofstream& operator << (std::ofstream& out, TechnicalStaff& obj); //запись объекта класса TechnicalStaff в файл

	virtual void edit(int n) override; //редактирование выбранного поля в объекте класса TechnicalStaff

	//bool operator ==(TechnicalStaff& obj);

	string getProfession(); //возвращает профессию работника
	void setProfession(string profession_); //устанавливает профессию работника
};

