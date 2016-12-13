#ifndef			__STUDENTS_H__
#define			__STUDENTS_H__

#include "Persons.h"

class Students : public Persons{
protected:
	int m_mssv;
public:
	Students();
	Students(char*, unsigned int, double*, int);
	~Students();

	unsigned int getAge();

	int getMSSV();
	void setMSSV(int);

};

#endif			//__STUDENTS_H__
