#include "SaleStaffs.h"

SaleStaffs::SaleStaffs()
{
	
}
SaleStaffs::SaleStaffs(char* name, unsigned int age, double* birthday, int id, int typeStaff, float salaryCoefficient) 
							:Staffs(name, age, birthday, id, typeStaff, salaryCoefficient)
{

}

SaleStaffs::~SaleStaffs()
{
	printf("\nSale Staffs Destructor");
}

float SaleStaffs::calSalary()
{
	return m_salaryCoefficient * 3000;
}