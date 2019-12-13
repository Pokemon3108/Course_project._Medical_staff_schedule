#include "pch.h"
#include "Doctor.h"

std::istream & operator>>(std::istream & in, Doctor & obj)
{
	in >> dynamic_cast<MedicalStaff&>(obj);
	cout << "���������:";
	inputLettersAndNumbers(in, obj.category);
	cout << "�������������:";
	inputLetters(in, obj.speciality);
	return in;
}

std::ostream & operator<<(std::ostream & out, const Doctor & obj)
{
	//����� ������� � ������� � ������������� � �������� ���������
	using namespace std;
	out << dynamic_cast<const MedicalStaff&>(obj);
	out << setiosflags(ios::left) << setw(10) << obj.category<< color<12, 3> << '|' << color<> << setw(10) 
		<<setw(19) << obj.speciality << color<12, 3> << '|' << color<>; 
	return out;
}

std::ifstream & operator>>(std::ifstream & in, Doctor & obj)
{
	in >> dynamic_cast<MedicalStaff&>(obj);
	std::getline(in, obj.category, '|');
	std::getline(in, obj.speciality, '\n');
	return in;
}

std::ofstream & operator<<(std::ofstream & out, Doctor & obj)
{
	out << dynamic_cast<MedicalStaff&>(obj);
	out << obj.category << '|' << obj.speciality << '\n';
	return out;

}

//bool Doctor::operator==(Doctor & obj)
//{
//	return (dynamic_cast<MedicalStaff&>(obj) == *(dynamic_cast<MedicalStaff*>(this)) && obj.category==category
//		&& obj.speciality==speciality);
//}

string Doctor::getCategory()
{
	return category;
}

void Doctor::setCategory(string category_)
{
	category = category_;
}

string Doctor::getSpeciality()
{
	return speciality;
}

void Doctor::setSpeciality(string speciality_)
{
	speciality = speciality_;
}

void Doctor::table(std::ostream & out)
{
	using namespace std;
	MedicalStaff::table(out);

	//����� ����� ������� � ���������� ����� �����-������������ ����� ���������� �������
	out << setiosflags(ios::left) << color<12, 3> << '|' << color<> << setw(10) << "���������" << 
		color<12, 3> << '|' << color<> << setw(19) << "�������������"; 
}

void Doctor::tableLines(std::ostream & out) const
{
	//����� �����-������������ ����� �������� �������
	MedicalStaff::tableLines(out);
	string str1(10, '-');
	string str2(19, '-');
	out << str1 << '+' << str2 << '+';
	
	Doctor obj;
	obj.graphicLines(out); //����� �����-������������ ����� ������� ������� ��� ������� � ��������
	
}

void Doctor::chooseParameters()
{
	MedicalStaff::chooseParameters();
	cout << "7-���������" << endl;
	cout << "8-�������������" << endl;
}

string Doctor::getParameter(int n)
{
	
	string parameter; //��������, ������� ���������� ����� ���� ���� ������� ��� ������
	
		parameter = MedicalStaff::getParameter(n); //�������� ��������� ���� ������������� ������
		if (parameter == "") //���� ���� ������������ ������� �� ���� �������, �� �������� � ������ ������� ������
		{
			switch (n)
			{
			case 7: //���� ������������ ������ 7 - � ��������, �� ������ ��������� � ���������� �������� ����
				std::cout << "���������:";
				inputLettersAndNumbers(cin, category);
				return "category";
			case 8: //���� ������������ ������ 7 - � ��������, �� ������ ������������� � ���������� �������� ����
				std::cout << "�������������:" << endl;
				inputLetters(cin, speciality);
				return "speciality";
			}
		}

	return parameter;
}

void Doctor::edit(int n)
{
	//����������� ���������, ������� ������ ������������
	MedicalStaff::edit(n);
	switch (n)
	{
	case 7: //���� ������������ ������ 7-� ��������, �� ����������� ���������
		std::cout << "���������:";
		inputLettersAndNumbers(cin, category);
		break;
	case 8: //���� ������������ ������ 8-� ��������, �� ����������� �������������
		std::cout << "�������������:" << endl;
		inputLetters(cin, speciality);
		break;
	}
}
