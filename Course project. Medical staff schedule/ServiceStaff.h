#pragma once
#include "TechnicalStaff.h"

class ServiceStaff : public TechnicalStaff
{
private:
	string workPlace;
public:
	ServiceStaff() = default;
	ServiceStaff(string place, string profession_, string firstName_, string surname_, string fatherName_, list<graphic> work, list<graphic> duty) :
		workPlace(place), TechnicalStaff(profession_, firstName_, surname_, fatherName_, work, duty) {};
	ServiceStaff(const ServiceStaff& obj) : workPlace(obj.workPlace),
		TechnicalStaff(obj.profession, obj.firstName, obj.surname, obj.fatherName, obj.work_graphic, obj.duty_graphic) {}

	~ServiceStaff() {};

	friend std::istream& operator >> (std::istream& in, ServiceStaff& obj);
	friend std::ostream& operator << (std::ostream& out, const ServiceStaff& obj);
	friend std::ifstream& operator >>(std::ifstream& in, ServiceStaff& obj);
	friend std::ofstream& operator << (std::ofstream& out, ServiceStaff& obj);
	
	virtual void table(std::ostream & out) override;
	virtual void tableLines(std::ostream& out) const override;

	virtual void edit(int n) override;

	virtual void chooseParameters() override;
	virtual string getParameter(int n) override;

	bool operator==(ServiceStaff& obj);

	string getWorkPlace();
	void setWorkPlace(string place);
};

