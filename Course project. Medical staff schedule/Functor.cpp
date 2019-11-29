#include "pch.h"
#include "Functor.h"

std::set<std::string>& Functor::getSetFields()
{
	return setFields;
}

int Functor::operator()(Staff & obj1, Staff & obj2)
{
	int i = 0;

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
	int i = (*this)(dynamic_cast<Staff&>(obj1), dynamic_cast<Staff&>(obj2));

	for (auto str : setFields)
		if (str == "department" && obj1.getDepartment() == obj2.getDepartment()) ++i;
		
	return i;
}

int Functor::operator()(TechnicalStaff & obj1, TechnicalStaff & obj2)
{
	int i = (*this)(dynamic_cast<Staff&>(obj1), dynamic_cast<Staff&>(obj2));

	for (auto str : setFields)
		if (str == "profession" && obj1.getProfession() == obj2.getProfession()) ++i;

	return i;
}

bool Functor::operator()(Doctor & obj1, Doctor & obj2)
{
	int i = (*this)(dynamic_cast<MedicalStaff&>(obj1), dynamic_cast<MedicalStaff&>(obj2));

	for (auto str : setFields)
	{
		if (str == "category" && obj1.getCategory() == obj2.getCategory()) ++i;
		if (str == "speciality" && obj1.getSpeciality() == obj2.getSpeciality()) ++i;
	}
	return (i == setFields.size());
}

bool Functor::operator()(Nurse & obj1, Nurse & obj2)
{
	int i = (*this)(dynamic_cast<MedicalStaff&>(obj1), dynamic_cast<MedicalStaff&>(obj2));

	for (auto str : setFields)
		if (str == "workProfile" && obj1.getWorkProfile() == obj2.getWorkProfile()) ++i;
		
	return (i == setFields.size());
}

bool Functor::operator()(ServiceStaff & obj1, ServiceStaff & obj2)
{
	int i = (*this)(dynamic_cast<TechnicalStaff&>(obj1), dynamic_cast<TechnicalStaff&>(obj2));

	for (auto str : setFields)
		if (str == "workPlace" && obj1.getWorkPlace() == obj2.getWorkPlace()) ++i;

	return (i == setFields.size());
}

bool Functor::operator()(AdministrativeStaff & obj1, AdministrativeStaff & obj2)
{
	int i = (*this)(dynamic_cast<TechnicalStaff&>(obj1), dynamic_cast<TechnicalStaff&>(obj2));

	for (auto str : setFields)
		if (str == "roomNumber" && obj1.getRoomNumber() == obj2.getRoomNumber()) ++i;

	return (i == setFields.size());
}
