#include "Students.h"

Students::Students()
{
}

Students::Students(char* name, unsigned int age, double* birthday, int mssv) :Persons(name, age, birthday), m_mssv(mssv)
{
}

unsigned int Students::getAge()
{
	return m_age + 1;
}

Students::~Students()
{
	printf("Students Destructor");
}

int Students::getMSSV()
{
	return m_mssv;
}

void Students::setMSSV(int mssv)
{
	m_mssv = mssv;
}

