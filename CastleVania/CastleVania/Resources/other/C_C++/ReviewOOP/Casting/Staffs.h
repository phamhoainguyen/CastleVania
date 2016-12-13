#ifndef			__STAFFS_H__
#define			__STAFFS_H__
#include "Persons.h"

class Staffs:public Persons
{
protected: 
	int m_id;
	int m_typeStaff;

	float m_salaryCoefficient;
public:
	Staffs();
	Staffs(char* name, unsigned int age, double* birthday, int id, int typeStaff, float salaryCoefficient);
	virtual ~Staffs();


	virtual char* getName();			// get name
	virtual unsigned int getAge();		// get age 
	double* getBirthday();			// get birthday

	virtual void setName(char*);				// set name
	virtual void setAge(unsigned int);		// set age 
	virtual void setBirthday(double*);			//set birthday

	virtual int getID();
	virtual void setID(int);

	virtual int getTypeStaff();
	virtual void setTyperStaff(int);

	virtual float getSalaryCoefficient();
	virtual void setSalaryCoefficient(float);

	virtual float calSalary() = 0;
};

#endif			//__STAFFS_H__