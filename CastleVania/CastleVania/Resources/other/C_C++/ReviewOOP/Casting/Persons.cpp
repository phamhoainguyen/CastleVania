#include "Persons.h"

Persons::Persons()
{
	//m_name = nullptr;    // mac dinh ham khoi tao se tu gan (m_name = nullptr)
	//m_birthday = nullptr;   //m_birthday = 0 (*m_birthday unknown)
	m_birthday = new double;  //m_birthday = 0xAAAA (*m_birthday = -121324235)
}

Persons::Persons(char* name, unsigned int age, double* birthday)
{
	m_birthday = new double;
	m_name = name;				// Neu khong co name thi m_name mac dinh khoi tao la <null> (m_name = nullptr)
	m_age = age;
	m_birthday = birthday;
}

Persons::~Persons()
{
	//delete m_name; khong cap phat thi k delete
	if (m_birthday)
		delete m_birthday;
	printf("\nPersons Destructor");
}

char* Persons::getName()
{
	return m_name;
}

void Persons::setName(char* name)
{
	m_name = name;
}

unsigned int Persons::getAge()
{
	return m_age;
}

void Persons::setAge(unsigned int age)
{
	m_age = age;
}

double* Persons::getBirthday()
{
	return m_birthday;
}

void Persons::setBirthday(double* birthday)
{
	m_birthday = birthday;
}

