#pragma once
#include "TechnicalStaff.h"
#include "pch.h"

class AdministrativeStaff : public TechnicalStaff
{
private:
	string roomNumber; //номер кабинета
public:
	AdministrativeStaff() = default;
	AdministrativeStaff(string room, string proffesion_, string firstName_, string surname_, string fatherName_, 
		list<graphic> work, list<graphic> duty) :
		roomNumber(room), TechnicalStaff(proffesion_, firstName_, surname_, fatherName_, work, duty) {}
	AdministrativeStaff(const AdministrativeStaff& obj) : roomNumber(obj.roomNumber),
		TechnicalStaff(obj.profession, obj.firstName, obj.surname, obj.fatherName, obj.work_graphic, obj.duty_graphic) {}

	~AdministrativeStaff() {};

	friend std::istream& operator >> (std::istream& in, AdministrativeStaff& obj); //инициализация объекта класса AdministrativeStaff с консоли
	friend std::ostream& operator << (std::ostream& out, const AdministrativeStaff& obj); //вывод объекта класса AdministrativeStaff на экран
	friend std::ifstream& operator >>(std::ifstream& in, AdministrativeStaff& obj); //чтение объекта класса AdministrativeStaff из файла
	friend std::ofstream& operator << (std::ofstream& out, AdministrativeStaff& obj); //запись объекта класса AdministrativeStaff в файл
	
	virtual void chooseParameters() override; //меню для выбора параметра для поиска/редактирования
	virtual string getParameter(int n) override; //возвращает строку с названием поля, которое подлежит редатированию

	virtual void table(std::ostream & out) override; //вывод шапки таблицы
	virtual void tableLines(std::ostream& out) const override; //вывод линий-разделителей в таблице

	virtual void edit(int n) override; //редактирование выбранного поля в объекте класса AdministrativeStaff

	//bool operator==(AdministrativeStaff& obj);

	string getRoomNumber(); //возвращает номер кабинета
	void setRoomNumber(string room); //устанавливает номер кабинета
};