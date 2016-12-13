#include "Staffs.h"

Staffs::Staffs(){

}
Staffs::Staffs(char* name, unsigned int age, double* birthday, int id, int typeStaff, float salaryCoefficient) :Persons(name, age, birthday), 
														m_id(id), m_typeStaff(typeStaff), m_salaryCoefficient(salaryCoefficient)
{

}
Staffs::~Staffs()
{
	printf("\nStaffs Destructor");
}


char* Staffs::getName()
{
	return m_name;
}

void Staffs::setName(char* name)
{
	m_name = name;
}

unsigned int Staffs::getAge()
{
	return m_age;
}

void Staffs::setAge(unsigned int age)
{
	m_age = age;
}

double* Staffs::getBirthday()
{
	return m_birthday;
}

void Staffs::setBirthday(double* birthday)
{
	m_birthday = birthday;
}

int Staffs::getID()
{
	return m_id;
}
void Staffs::setID(int id)
{
	m_id = id;
}

int Staffs::getTypeStaff()
{
	return m_typeStaff;
}
void Staffs::setTyperStaff(int typeStaff)
{
	m_typeStaff = typeStaff;
}

float Staffs::getSalaryCoefficient()
{
	return m_salaryCoefficient;
}
void Staffs::setSalaryCoefficient(float salaryCoefficient)
{
	m_salaryCoefficient = salaryCoefficient;
}
