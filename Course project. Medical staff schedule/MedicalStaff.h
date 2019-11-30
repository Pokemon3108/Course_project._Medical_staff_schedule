#pragma once
#include "Staff.h"

class MedicalStaff abstract: public Staff
{
protected:
	string department;
public:
	MedicalStaff() = default;
	MedicalStaff(string department, string firstName_, string surname_, string fatherName_, list<graphic> work, list<graphic> duty) :
		department(department), Staff(firstName_, surname_, fatherName_, work, duty) {}
	MedicalStaff(const MedicalStaff& obj) :
		Staff(obj.firstName, obj.surname, obj.fatherName, obj.work_graphic, obj.duty_graphic), department(obj.department) {}
	~MedicalStaff() {};

	friend std::istream& operator >> (std::istream& in, MedicalStaff& obj);
	friend std::ostream& operator << (std::ostream& out, const MedicalStaff& obj);

	virtual void table(std::ostream & out) override;
	virtual void tableLines(std::ostream& out) const override;

	virtual void chooseParameters() override;
	virtual std::string getParameter(int n) override;

	bool operator ==(MedicalStaff& obj);
	bool operator !=(MedicalStaff& obj);

	string getDepartment() const;
	void setDepartment(string department);
};

