#pragma once
#include "Doctor.h"
#include "ServiceStaff.h"
#include "Nurse.h"
#include "AdministrativeStaff.h"
#include "pch.h"


class Functor
{
private:
	set<string> setFields; //множество строк-полей для поиска

public:
	Functor() {};
	~Functor() {};

	int operator()(Staff& obj1, Staff& obj2); //возвращает число выбранных полей, которые совпадают у двух объектов класса Staff
	int operator()(MedicalStaff& obj1, MedicalStaff& obj2); //возвращает число выбранных полей, которые совпадают у двух объектов класса MedicalStaff
	int operator()(TechnicalStaff& obj1, TechnicalStaff& obj2);//возвращает число выбранных полей, которые совпадают у двух объектов класса TechnicalStaff
	
	bool operator()(Doctor& obj1, Doctor& obj2); //определяет, равны ли выбранные поля у объектов класса Doctor
	bool operator()(Nurse& obj1, Nurse& obj2); //определяет, равны ли выбранные поля у объектов класса Nurse
	bool operator()(ServiceStaff& obj1, ServiceStaff& obj2); //определяет, равны ли выбранные поля у объектов класса ServiceStaff
	bool operator()(AdministrativeStaff& obj1, AdministrativeStaff& obj2); //определяет, равны ли выбранные поля у объектов класса Administrative
	
	set<string>& getSetFields(); //возвращает множество строк-полей для поиска
};
