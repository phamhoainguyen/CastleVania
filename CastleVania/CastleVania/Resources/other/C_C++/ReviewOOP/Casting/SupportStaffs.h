#ifndef				__SUPPORT_STAFFS_H__
#define				__SUPPORT_STAFFS_H__

#include "Staffs.h"

class SupportStaffs :public Staffs
{
private:

public:
	SupportStaffs();
	SupportStaffs(char* name, unsigned int age, double* birthday, int id, int typeStaff, float salaryCoefficient);
	~SupportStaffs();
	float calSalary();
};

#endif				//__SUPPORT_STAFFS_H__