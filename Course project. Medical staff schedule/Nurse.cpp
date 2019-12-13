#include "pch.h"
#include "Nurse.h"


std::istream & operator>>(std::istream & in, Nurse & obj)
{
	in >> dynamic_cast<MedicalStaff&>(obj);
	cout << "������� ������:";
	inputLetters(in, obj.workprofile);
	return in;
}

std::ostream & operator<<(std::ostream & out, const Nurse & obj)
{
	//����� ������� � ������� � ������������� � �������� ���������
	using namespace std;
	out << dynamic_cast<const MedicalStaff&>(obj);
	out << setiosflags(ios::left) << setw(24) << obj.workprofile<< color<12, 3> << '|' << color<>;
	return out;
}

std::ifstream & operator>>(std::ifstream & in, Nurse & obj)
{
	in >> dynamic_cast<MedicalStaff&>(obj);
	std::getline(in, obj.workprofile, '\n');
	return in;
}

std::ofstream & operator<<(std::ofstream & out, Nurse & obj)
{
	out << dynamic_cast<MedicalStaff&>(obj);
	out << obj.workprofile << '\n';
	return out;
}

//bool Nurse::operator==(Nurse & obj)
//{
//	return (dynamic_cast<MedicalStaff&>(obj) == *(dynamic_cast<MedicalStaff*>(this))
//		&& obj.workprofile == workprofile);
//}

void Nurse::setWorkProfile(string profile)
{
	workprofile = profile;
}

string Nurse::getWorkProfile()
{
	return workprofile;
}

void Nurse::table(std::ostream & out)
{
	using namespace std;
	MedicalStaff::table(out);
	out << setiosflags(ios::left) << color<12, 3> << '|' << color<><<setw(24) << "������� ������";
}

void Nurse::tableLines(std::ostream & out) const
{
	MedicalStaff::tableLines(out);
	string str(24, '-');
	out << str << '+';
	Nurse obj;
	obj.graphicLines(out);
}

void Nurse::chooseParameters()
{
	MedicalStaff::chooseParameters();
	cout << "7-������� ������" << endl;
}

string Nurse::getParameter(int n)
{
	
	string parameter; //��������, ������� ���������� ����� ���� ���� ������� ��� ������
	
	parameter = MedicalStaff::getParameter(n); //�������� ��������� ���� ������������� ������
	if (parameter == "") //���� ���� ������������ ������� �� ���� �������, �� �������� � ������ ������� ������
	{
		switch (n)
		{
		case 7:
			std::cout << "������� ������:";
			inputLettersAndNumbers(cin, workprofile);
			return "workProfile";
		}
	}
	//���� ��� ������ �������� ������������� ������, �� ������� ���
	return parameter;
}

void Nurse::edit(int n)
{
	//����������� ���������, ������� ������ ������������
	MedicalStaff::edit(n);
	if (n == 7)
	{
		//���� ������������ ������ 7-� ��������, �� ����������� ������� ������
		std::cout << "������� ������:";
		inputLetters(cin, workprofile);
	}
}
