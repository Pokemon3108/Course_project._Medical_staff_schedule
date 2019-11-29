#pragma once
#include "MedicalStaff.h"

class Doctor : public MedicalStaff
{
private:
	string category;
	string speciality;

public:
	Doctor() = default;
	Doctor(string category_, string speciality_, string department_, string firstName, string surname_, 
		string fatherName_, list<graphic> work, list<graphic> duty) :
		category(category_), speciality(speciality_), MedicalStaff(department_, firstName, surname_, fatherName_, work, duty) {}
	Doctor(const Doctor& obj) : category(obj.category), speciality(obj.speciality),
		MedicalStaff(obj.department, obj.firstName, obj.surname, obj.fatherName, obj.work_graphic, obj.duty_graphic) {}
	~Doctor() {};

	friend std::istream& operator >> (std::istream& in, Doctor& obj);
	friend std::ostream& operator << (std::ostream& out, const Doctor& obj);

	virtual void table(std::ostream & out) override;

	virtual void chooseParameters() override;
	virtual string getParameter(int n) override;

	bool operator ==(Doctor&obj);
	bool operator !=(Doctor&obj);

	string getCategory();
	void setCategory(string category_);

	string getSpeciality();
	void setSpeciality(string speciality_);
};

