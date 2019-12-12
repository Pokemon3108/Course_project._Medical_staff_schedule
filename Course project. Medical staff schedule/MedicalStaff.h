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

	friend std::istream& operator >> (std::istream& in, MedicalStaff& obj); //������������� ������� ������ MedicalStaff � �������
	friend std::ostream& operator << (std::ostream& out, const MedicalStaff& obj); //����� ������� ������ MedicalStaff �� �����
	friend std::ifstream& operator >>(std::ifstream& in, MedicalStaff& obj); //������ ������� ������ MedicalStaff �� �����
	friend std::ofstream& operator << (std::ofstream& out, MedicalStaff& obj); //������ ������� ������ MedicalStaff � ����

	virtual void table(std::ostream & out) override; //����� ����� �������
	virtual void tableLines(std::ostream& out) const override; //����� �����-������������ � �������

	virtual void chooseParameters() override; //���� ��� ������ ��������� ��� ������/��������������
	virtual string getParameter(int n) override; //���������� ������ � ��������� ����, ������� �������� �������������

	virtual void edit(int n) override; //�������������� ���������� ���� � ������� ������ MedicalStaff

	//bool operator ==(MedicalStaff& obj);

	string getDepartment() const; //���������� ���������
	void setDepartment(string department_); //������������� ���������
};
