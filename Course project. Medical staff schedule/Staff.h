#pragma once
#include <iostream>
#include <list>
#include "InputError.h"


struct graphic
{
	int hour1;
	int hour2;
	string weekday;
};

class Staff abstract
{
protected:
	string firstName;
	string surname;
	string fatherName;
	list<graphic> work_graphic;
	list<graphic> duty_graphic;
public:
	Staff() = default;
	Staff(string firstName, string surname_, string fatherName, list<graphic> work, list<graphic> duty) :
		firstName(firstName), surname(surname_), fatherName(fatherName), work_graphic(work), duty_graphic(duty) {}
	Staff(const Staff& obj) : firstName(obj.firstName), surname(obj.surname), fatherName(obj.fatherName),
		work_graphic(obj.work_graphic), duty_graphic(obj.duty_graphic) {}
	~Staff() {}

	friend std::istream& operator >> (std::istream& in, Staff& obj);
	friend std::ostream& operator << (std::ostream& out, const Staff& obj);

	void inputGraphic(std::istream& in, list<graphic>& list_graphic);
	virtual void table(std::ostream & out);
	void tableGraphic(std::ostream & out);
	void outputGraphic(std::ostream & out, list<graphic>& list_graphic);

	virtual void chooseParameters();
	virtual std::string getParameter(int n);

	bool operator !=(Staff& obj);
	bool operator >(Staff& obj);
	bool operator <(Staff& obj);
	bool operator ==(Staff& obj);
	
	string getFirstName() const;
	void setFirstName(string name);
	
	string getSurname() const;
	void setSurname(string sur);
	
	string getFatherName() const;
	void setFatherName(string fatherName_);
	
	int getHour1(string day, list<graphic>& gr) const;
	void setHour1(string day, int hour, list<graphic>& gr);
	
	int getHour2(string day, list<graphic>& gr) const;
	void setHour2(string day, int hour, list<graphic>& gr);

	list<graphic>& getDutyGraphic();
	list<graphic>& getWorkGraphic();

	bool daysInGraphic(list<graphic>& objInTree, list<graphic>& objSearch);
};