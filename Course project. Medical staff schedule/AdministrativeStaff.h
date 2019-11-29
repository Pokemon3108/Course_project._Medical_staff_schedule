#pragma once
#include "TechnicalStaff.h"
#include "pch.h"

class AdministrativeStaff : public TechnicalStaff
{
private:
	string roomNumber;
public:
	AdministrativeStaff() = default;
	AdministrativeStaff(string room, string proffesion_, string firstName_, string surname_, string fatherName_, 
		list<graphic> work, list<graphic> duty) :
		roomNumber(room), TechnicalStaff(proffesion_, firstName_, surname_, fatherName_, work, duty) {}
	AdministrativeStaff(const AdministrativeStaff& obj) : roomNumber(obj.roomNumber),
		TechnicalStaff(obj.profession, obj.firstName, obj.surname, obj.fatherName, obj.work_graphic, obj.duty_graphic) {}

	~AdministrativeStaff() {};

	friend std::istream& operator >> (std::istream& in, AdministrativeStaff& obj);
	friend std::ostream& operator << (std::ostream& out, const AdministrativeStaff& obj);
	
	virtual void chooseParameters() override;
	virtual string getParameter(int n) override;

	bool operator==(AdministrativeStaff& obj);
	bool operator!=(AdministrativeStaff& obj);

	string getRoomNumber();
	void setRoomNumber(string room);
};
