#pragma once
#include "Staff.h"

class MedicalStaff abstract: public Staff
{
protected:
	string department;
public:
	MedicalStaff() = default;
	MedicalStaff(string department, string firstName_, string surname_, string fatherName_, list<graphic> work, list<graphic> duty) :
		department(department), Staff(firstName_, surname_, fatherName_, work, duty) {}
	MedicalStaff(const MedicalStaff& obj) :
		Staff(obj.firstName, obj.surname, obj.fatherName, obj.work_graphic, obj.duty_graphic), department(obj.department) {}
	~MedicalStaff() {};

	friend std::istream& operator >> (std::istream& in, MedicalStaff& obj); //инициализация объекта класса MedicalStaff с консоли
	friend std::ostream& operator << (std::ostream& out, const MedicalStaff& obj); //вывод объекта класса MedicalStaff на экран
	friend std::ifstream& operator >>(std::ifstream& in, MedicalStaff& obj); //чтение объекта класса MedicalStaff из файла
	friend std::ofstream& operator << (std::ofstream& out, MedicalStaff& obj); //запись объекта класса MedicalStaff в файл

	virtual void table(std::ostream & out) override; //вывод шапки таблицы
	virtual void tableLines(std::ostream& out) const override; //вывод линий-разделителей в таблице

	virtual void chooseParameters() override; //меню для выбора параметра для поиска/редактирования
	virtual string getParameter(int n) override; //возвращает строку с названием поля, которое подлежит редатированию

	virtual void edit(int n) override; //редактирование выбранного поля в объекте класса MedicalStaff

	//bool operator ==(MedicalStaff& obj);

	string getDepartment() const; //возвращает отделение
	void setDepartment(string department_); //устанавливает отделение
};
