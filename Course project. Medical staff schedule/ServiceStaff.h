#pragma once
#include "TechnicalStaff.h"

class ServiceStaff : public TechnicalStaff
{
private:
	string workPlace; //рабочая область
public:
	ServiceStaff() = default;
	ServiceStaff(string place, string profession_, string firstName_, string surname_, string fatherName_, list<graphic> work, list<graphic> duty) :
		workPlace(place), TechnicalStaff(profession_, firstName_, surname_, fatherName_, work, duty) {};
	ServiceStaff(const ServiceStaff& obj) : workPlace(obj.workPlace),
		TechnicalStaff(obj.profession, obj.firstName, obj.surname, obj.fatherName, obj.work_graphic, obj.duty_graphic) {}

	~ServiceStaff() {};

	friend std::istream& operator >> (std::istream& in, ServiceStaff& obj); //инициализация объекта класса ServiceStaff с консоли
	friend std::ostream& operator << (std::ostream& out, const ServiceStaff& obj); //вывод объекта класса ServiceStaff на экран
	friend std::ifstream& operator >>(std::ifstream& in, ServiceStaff& obj); //чтение объекта класса ServiceStaff из файла
	friend std::ofstream& operator << (std::ofstream& out, ServiceStaff& obj); //запись объекта класса ServiceStaff в файл
	
	virtual void table(std::ostream & out) override; //вывод шапки таблицы
	virtual void tableLines(std::ostream& out) const override; //вывод линий-разделителей в таблице

	virtual void edit(int n) override; //редактирование выбранного поля в объекте класса ServiceStaff

	virtual void chooseParameters() override; //меню для выбора параметра для поиска/редактирования
	virtual string getParameter(int n) override; //возвращает строку с названием поля, которое подлежит редатированию

	//bool operator==(ServiceStaff& obj);

	string getWorkPlace(); //устанавливает рабочую область
	void setWorkPlace(string place); //возвращает рабочую область
};
