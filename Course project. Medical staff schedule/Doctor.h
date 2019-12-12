#pragma once
#include "MedicalStaff.h"

class Doctor : public MedicalStaff
{
private:
	string category; //категория
	string speciality; //специальность

public:
	Doctor() = default;
	Doctor(string category_, string speciality_, string department_, string firstName, string surname_, 
		string fatherName_, list<graphic> work, list<graphic> duty) :
		category(category_), speciality(speciality_), MedicalStaff(department_, firstName, surname_, fatherName_, work, duty) {}
	Doctor(const Doctor& obj) : category(obj.category), speciality(obj.speciality),
		MedicalStaff(obj.department, obj.firstName, obj.surname, obj.fatherName, obj.work_graphic, obj.duty_graphic) {}
	~Doctor() {};

	friend std::istream& operator >> (std::istream& in, Doctor& obj); //инициализация объекта класса Doctor с консоли
	friend std::ostream& operator << (std::ostream& out, const Doctor& obj); //вывод объекта класса Doctor на экран
	friend std::ifstream& operator >>(std::ifstream& in, Doctor& obj); //чтение объекта класса Doctor из файла
	friend std::ofstream& operator << (std::ofstream& out, Doctor& obj); //запись объекта класса Doctor в файл

	virtual void table(std::ostream & out) override; //вывод шапки таблицы
	virtual void tableLines(std::ostream& out)const override; //вывод линий-разделителей в таблиц

	virtual void chooseParameters() override; //меню для выбора параметра для поиска/редактирования
	virtual string getParameter(int n) override; //возвращает строку с названием поля, которое подлежит редатированию

	virtual void edit(int n) override; //редактирование выбранного поля в объекте класса AdministrativeStaff

	//bool operator ==(Doctor&obj);
	
	string getCategory(); //возвращает категорию
	void setCategory(string category_); //устнавливает категорию

	string getSpeciality(); //возвращает специальность
	void setSpeciality(string speciality_); //устанавливает специальность
};



