#pragma once
#include "Doctor.h"
#include "ServiceStaff.h"
#include "Nurse.h"
#include "AdministrativeStaff.h"
#include "pch.h"
//#include <string>

class Functor
{
private:
	set<string> setFields;

public:
	Functor() {};
	~Functor() {};

	int operator()(Staff& obj1, Staff& obj2);
	int operator()(MedicalStaff& obj1, MedicalStaff& obj2);
	int operator()(TechnicalStaff& obj1, TechnicalStaff& obj2);
	
	bool operator()(Doctor& obj1, Doctor& obj2);
	bool operator()(Nurse& obj1, Nurse& obj2);
	bool operator()(ServiceStaff& obj1, ServiceStaff& obj2);
	bool operator()(AdministrativeStaff& obj1, AdministrativeStaff& obj2);
	
	set<string>& getSetFields();
};
