#include "pch.h"
#include "MedicalStaff.h"


//bool MedicalStaff::operator==(MedicalStaff & obj)
//{
//	return (dynamic_cast<Staff&>(obj) == *(dynamic_cast<Staff*>(this)) && obj.department == department);
//}

string MedicalStaff::getDepartment() const
{
	return department;
}

void MedicalStaff::setDepartment(string department_)
{
	department = department_;
}

std::istream & operator>>(std::istream & in, MedicalStaff & obj)
{
	in >> dynamic_cast<Staff&>(obj);
	cout << "���������:";
	inputLetters(in, obj.department);
	return in;
}

std::ostream & operator<<(std::ostream & out, const MedicalStaff & obj)
{
	//����� ������� � ������� � ������������� � �������� ���������
	using namespace std;
	out << dynamic_cast<const Staff&>(obj);
	out << setiosflags(ios::left) << setw(19) << obj.department<< color<12, 3> << '|' << color<>;
	return out;
	
}

std::ifstream & operator>>(std::ifstream & in, MedicalStaff & obj)
{
	in >> dynamic_cast<Staff&>(obj);
	std::getline(in, obj.department, '|');
	return in;
}

std::ofstream & operator<<(std::ofstream & out, MedicalStaff & obj)
{
	out << dynamic_cast<Staff&>(obj);
	out << obj.department << '|';
	return out;
}

void MedicalStaff::table(std::ostream & out)
{
	Staff::table(out);

	//����� ����� ������� � ���������� ����� �����-������������ ����� ���������� �������
	out << std::setiosflags(std::ios::left)<< color<12,3> << '|' << color<><< setw(19) << "���������";
}

void MedicalStaff::tableLines(std::ostream & out) const
{
	//����� �����-������������ ����� �������� �������
	Staff::tableLines(out);
	string str1(19, '-');
	out << str1 << '+';
}


void MedicalStaff::chooseParameters()
{
	Staff::chooseParameters();
	cout << "6-���������" << endl;
}

std::string MedicalStaff::getParameter(int n)
{
	string parameter = Staff::getParameter(n); //��������, ������� ���������� ����� ���� ���� ������� ��� ������
	if (parameter == "") //���� ���� ������������ ������� �� ���� �������, �� �������� � ������ ������� ������
	{
		switch (n)
		{
		case 6:
			cout << "���������:";
			inputLetters(cin, department);
			return "department";

		default:
			return "";
		}
	}
	//���� ��� ������ �������� ������������� ������, �� ������� ���
	return parameter;
}

void MedicalStaff::edit(int n)
{
	//����������� ���������, ������� ������ ������������
	Staff::edit(n);
	if (n == 6) //���� ������������ ������ 6-� ��������, �� ����������� ���������
	{
		cout << "���������:";
		inputLetters(cin, department);
	}
}
