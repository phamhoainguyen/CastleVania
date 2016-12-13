#ifndef				__SALE_STAFF_H__
#define				__SALE_STAFF_H__
#include "Staffs.h"

class SaleStaffs :public Staffs
{
private:

public:
	SaleStaffs();
	SaleStaffs(char* name, unsigned int age, double* birthday, int id, int typeStaff, float salaryCoefficient);
	virtual ~SaleStaffs();
	float calSalary();
};
#endif				//__SALE_STAFF_H__