#include "pch.h"
#include "Functor.h"

std::set<std::string>& Functor::getSetFields()
{
	return setFields;
}

int Functor::operator()(Staff & obj1, Staff & obj2)
{
	int i = 0; //счётчик для подсчёта количества совпадаемых полей в объектах

	//в цикле проходим по множеству полей-строк
	//если в сете нашли строку с именем определённого поля класса Staff, то сравниваем найденные поля объектов
	//если поля совпали, то увеличиваем счётчик на единицу
	for (string str : setFields)
	{
		if (str == "firstName" && obj1.getFirstName() == obj2.getFirstName()) ++i;
		if (str == "surname" && obj1.getSurname() == obj2.getSurname()) ++i;
		if (str == "fatherName" && obj1.getFatherName() == obj2.getFatherName()) ++i;
		if (str == "weekdayDuty" && obj1.daysInGraphic(obj1.getDutyGraphic(), obj1.getWorkGraphic())) ++i;
		if (str == "weekdayWork" && obj1.daysInGraphic(obj1.getWorkGraphic(), obj2.getWorkGraphic())) ++i;
	}
	return i;
}

int Functor::operator()(MedicalStaff & obj1, MedicalStaff & obj2)
{
	//в счётчике хранится количество совпадаемых полей родительского класса Staff
	int i = (*this)(dynamic_cast<Staff&>(obj1), dynamic_cast<Staff&>(obj2)); 

	//в цикле проходим по множеству полей-строк
	//если поле department подлежит поиску и информация в нём совпадает, то счетчик увеличивается
	for (auto str : setFields)
		if (str == "department" && obj1.getDepartment() == obj2.getDepartment()) ++i; 
		
	return i;
}

int Functor::operator()(TechnicalStaff & obj1, TechnicalStaff & obj2)
{
	//в счётчике хранится количество совпадаемых полей родительского класса Staff
	int i = (*this)(dynamic_cast<Staff&>(obj1), dynamic_cast<Staff&>(obj2));

	//в цикле проходим по множеству полей-строк
	//если поле profession подлежит поиску и информация в нём совпадает, то счетчик увеличивается
	for (auto str : setFields)
		if (str == "profession" && obj1.getProfession() == obj2.getProfession()) ++i;

	return i;
}

bool Functor::operator()(Doctor & obj1, Doctor & obj2)
{
	//в счётчике хранится количество совпадаемых полей родительского класса MedicalStaff
	int i = (*this)(dynamic_cast<MedicalStaff&>(obj1), dynamic_cast<MedicalStaff&>(obj2));

	//в цикле проходим по множеству полей-строк
	//если поле category подлежит поиску и информация в нём совпадает, то счетчик увеличивается
	//если поле speciality подлежит поиску и информация в нём совпадает, то счетчик увеличивается
	for (auto str : setFields)
	{
		if (str == "category" && obj1.getCategory() == obj2.getCategory()) ++i;
		if (str == "speciality" && obj1.getSpeciality() == obj2.getSpeciality()) ++i;
	}
	return (i == setFields.size()); //возвращает true, если количество совпадаемых полей равно размеру множества строк
}

bool Functor::operator()(Nurse & obj1, Nurse & obj2)
{
	//в счётчике хранится количество совпадаемых полей родительского класса MedicalStaff
	int i = (*this)(dynamic_cast<MedicalStaff&>(obj1), dynamic_cast<MedicalStaff&>(obj2));

	//в цикле проходим по множеству полей-строк
	//если поле workProfile подлежит поиску и информация в нём совпадает, то счетчик увеличивается
	for (auto str : setFields)
		if (str == "workProfile" && obj1.getWorkProfile() == obj2.getWorkProfile()) ++i;
		
	return (i == setFields.size()); //возвращает true, если количество совпадаемых полей равно размеру множества строк
}

bool Functor::operator()(ServiceStaff & obj1, ServiceStaff & obj2)
{
	//в счётчике хранится количество совпадаемых полей родительского класса TechnicalStaff
	int i = (*this)(dynamic_cast<TechnicalStaff&>(obj1), dynamic_cast<TechnicalStaff&>(obj2));

	//в цикле проходим по множеству полей-строк
	//если поле workPlace подлежит поиску и информация в нём совпадает, то счетчик увеличивается
	for (auto str : setFields)
	for (auto str : setFields)
		if (str == "workPlace" && obj1.getWorkPlace() == obj2.getWorkPlace()) ++i;

	return (i == setFields.size()); //возвращает true, если количество совпадаемых полей равно размеру множества строк
}

bool Functor::operator()(AdministrativeStaff & obj1, AdministrativeStaff & obj2)
{
	//в счётчике хранится количество совпадаемых полей родительского класса TechnicalStaff
	int i = (*this)(dynamic_cast<TechnicalStaff&>(obj1), dynamic_cast<TechnicalStaff&>(obj2));

	//в цикле проходим по множеству полей-строк
	//если поле roomNumber подлежит поиску и информация в нём совпадает, то счетчик увеличивается
	for (auto str : setFields)
		if (str == "roomNumber" && obj1.getRoomNumber() == obj2.getRoomNumber()) ++i;

	return (i == setFields.size()); //возвращает true, если количество совпадаемых полей равно размеру множества строк
}
