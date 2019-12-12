#pragma once
#include "MedicalStaff.h"

class Nurse : public MedicalStaff
{
private:
	string workprofile; //профиль работы
public:
	Nurse() = default;
	Nurse(string profile, string department, string firstName_, string surname_, string fatherName_, 
		list<graphic> work, list<graphic> duty) :
		workprofile(profile), MedicalStaff(department, firstName_, surname_, fatherName_, work, duty) {}
	Nurse(const Nurse& obj) : workprofile(obj.workprofile),
		MedicalStaff(obj.department, obj.firstName, obj.surname, obj.fatherName, obj.work_graphic, obj.duty_graphic) {}

	~Nurse() {}

	friend std::istream& operator >> (std::istream& in, Nurse& obj); //инициализация объекта класса Nurse с консоли
	friend std::ostream& operator << (std::ostream& out, const Nurse& obj); //вывод объекта класса Nurse на экран
	friend std::ifstream& operator >>(std::ifstream& in, Nurse& obj); //чтение объекта класса Nurse из файла
	friend std::ofstream& operator << (std::ofstream& out, Nurse& obj); //запись объекта класса Nurse в файл

	virtual void table(std::ostream & out) override; //вывод шапки таблицы
	virtual void tableLines(std::ostream& out) const; //вывод линий-разделителей в таблице

	virtual void chooseParameters() override; //меню для выбора параметра для поиска/редактирования
	virtual string getParameter(int n) override; //возвращает строку с названием поля, которое подлежит редатированию

	virtual void edit(int n) override; //редактирование выбранного поля в объекте класса Nurse


	//bool operator==(Nurse& obj);

	void setWorkProfile(string profile); //устанавливает профиль работы
	string getWorkProfile(); //возвращает профиль работы
};