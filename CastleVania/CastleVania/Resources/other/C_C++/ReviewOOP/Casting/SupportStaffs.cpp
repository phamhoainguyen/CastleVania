#include "SupportStaffs.h"

SupportStaffs::SupportStaffs()
{

}
SupportStaffs::SupportStaffs(char* name, unsigned int age, double* birthday, int id, int typeStaff, float salaryCoefficient)
								:Staffs(name, age, birthday, id, typeStaff, salaryCoefficient)
{

}

SupportStaffs::~SupportStaffs()
{

}
float SupportStaffs::calSalary()
{
	return m_salaryCoefficient * 4000;
}