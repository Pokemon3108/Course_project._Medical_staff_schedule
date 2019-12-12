#pragma once
#include "MedicalStaff.h"

class Nurse : public MedicalStaff
{
private:
	string workprofile; //������� ������
public:
	Nurse() = default;
	Nurse(string profile, string department, string firstName_, string surname_, string fatherName_, 
		list<graphic> work, list<graphic> duty) :
		workprofile(profile), MedicalStaff(department, firstName_, surname_, fatherName_, work, duty) {}
	Nurse(const Nurse& obj) : workprofile(obj.workprofile),
		MedicalStaff(obj.department, obj.firstName, obj.surname, obj.fatherName, obj.work_graphic, obj.duty_graphic) {}

	~Nurse() {}

	friend std::istream& operator >> (std::istream& in, Nurse& obj); //������������� ������� ������ Nurse � �������
	friend std::ostream& operator << (std::ostream& out, const Nurse& obj); //����� ������� ������ Nurse �� �����
	friend std::ifstream& operator >>(std::ifstream& in, Nurse& obj); //������ ������� ������ Nurse �� �����
	friend std::ofstream& operator << (std::ofstream& out, Nurse& obj); //������ ������� ������ Nurse � ����

	virtual void table(std::ostream & out) override; //����� ����� �������
	virtual void tableLines(std::ostream& out) const; //����� �����-������������ � �������

	virtual void chooseParameters() override; //���� ��� ������ ��������� ��� ������/��������������
	virtual string getParameter(int n) override; //���������� ������ � ��������� ����, ������� �������� �������������

	virtual void edit(int n) override; //�������������� ���������� ���� � ������� ������ Nurse


	//bool operator==(Nurse& obj);

	void setWorkProfile(string profile); //������������� ������� ������
	string getWorkProfile(); //���������� ������� ������
};