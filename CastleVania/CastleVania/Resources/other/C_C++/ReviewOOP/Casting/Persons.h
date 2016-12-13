#ifndef			__PERSONS_H__
#define			__PERSONS_H__
#include <stdio.h>

class Persons{
protected:
	char* m_name;
	unsigned int m_age;
	double* m_birthday;

public:
	Persons();
	Persons(char*, unsigned int, double*);
	~Persons();

	char* getName();			// get name
	unsigned int getAge();		// get age 
	double* getBirthday();			// get birthday

	void setName(char*);				// set name
	void setAge(unsigned int);		// set age 
	void setBirthday(double*);			//set birthday

};


#endif			//__PERSONS_H__
