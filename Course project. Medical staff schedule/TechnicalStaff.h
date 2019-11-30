#pragma once
#include "Staff.h"

class TechnicalStaff abstract : public Staff
{
protected:
	string profession;
public:
	TechnicalStaff() = default;
	TechnicalStaff(string profession_, string firstName_, string surname_, string fatherName_, 
		list<graphic> work, list<graphic> duty) :
		profession(profession_), Staff(firstName_, surname_, fatherName_, work, duty) {}
	TechnicalStaff(const TechnicalStaff& obj) :
		Staff(obj.firstName, obj.surname, obj.fatherName, obj.work_graphic, obj.duty_graphic), profession(obj.profession) {}

	~TechnicalStaff() {};

	void chooseParameters();
	string getParameter(int n);

	virtual void table(std::ostream & out) override;
	virtual void tableLines(std::ostream& out) const override;

	friend std::istream& operator >> (std::istream& in, TechnicalStaff& obj);
	friend std::ostream& operator << (std::ostream& out, const TechnicalStaff& obj);

	bool operator ==(TechnicalStaff& obj);
	bool operator !=(TechnicalStaff& obj);

	string getProfession();
	void setProfession(string profession_);
};

