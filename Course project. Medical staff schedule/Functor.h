#pragma once
#include "Doctor.h"
#include "ServiceStaff.h"
#include "Nurse.h"
#include "AdministrativeStaff.h"
#include "pch.h"


class Functor
{
private:
	set<string> setFields; //��������� �����-����� ��� ������

public:
	Functor() {};
	~Functor() {};

	int operator()(Staff& obj1, Staff& obj2); //���������� ����� ��������� �����, ������� ��������� � ���� �������� ������ Staff
	int operator()(MedicalStaff& obj1, MedicalStaff& obj2); //���������� ����� ��������� �����, ������� ��������� � ���� �������� ������ MedicalStaff
	int operator()(TechnicalStaff& obj1, TechnicalStaff& obj2);//���������� ����� ��������� �����, ������� ��������� � ���� �������� ������ TechnicalStaff
	
	bool operator()(Doctor& obj1, Doctor& obj2); //����������, ����� �� ��������� ���� � �������� ������ Doctor
	bool operator()(Nurse& obj1, Nurse& obj2); //����������, ����� �� ��������� ���� � �������� ������ Nurse
	bool operator()(ServiceStaff& obj1, ServiceStaff& obj2); //����������, ����� �� ��������� ���� � �������� ������ ServiceStaff
	bool operator()(AdministrativeStaff& obj1, AdministrativeStaff& obj2); //����������, ����� �� ��������� ���� � �������� ������ Administrative
	
	set<string>& getSetFields(); //���������� ��������� �����-����� ��� ������
};
