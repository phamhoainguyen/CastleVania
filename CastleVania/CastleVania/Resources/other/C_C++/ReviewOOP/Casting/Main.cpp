#include <stdio.h>
#include "Define.h"
#include "Students.h"
#include "SaleStaffs.h"
#include "SupportStaffs.h"

int main()
{
	double* pBirthDay = new double;
	*pBirthDay = 1996;

	////////////////////////////////////////////////Thanh phan cua class co con tro
	//Persons *pPerson = new Persons("Pham Hoai Nguyen", 20, pBirthDay);
	//printf("Name: %s\n Age: %d \n BirthDay: %d\n", pPerson->getName(), pPerson->getAge(), *(pPerson->getBirthday()));
	//Persons* pPerson = new Persons;
	//printf("Name: %s\n Age: %d \n BirthDay: %x\n", pPerson->getName(), pPerson->getAge(), pPerson->getBirthday());


	//Persons*  pPerson = new Students("Pham Hoai Nguyen", 20, pBirthDay, 14);   // cho thay su khac nhau giua virtual va khong virtual
	//Students* pPerson = new Students("Pham Hoai Nguyen", 20, pBirthDay, 14);
	//printf("Name: %s\n Age: %d \n BirthDay: %f\n MSSV: %d\n", pPerson->getName(), pPerson->getAge(), *(pPerson->getBirthday()), pPerson->getMSSV());


	//////////////////////////////////// OVERRIDE/////////////////////////////////////////////
	Staffs* pStaff = new SaleStaffs("Pham Hoai Nguyen", 20, pBirthDay, 1452, _TYPE_SALE_STAFF_, _SALARY_COEFFICIENT_SALE_STAFF);

	//printf("Name: %s\n Age: %d \n BirthDay: %lf\n ID: %d\n Type Staff: %d\n Salary Coefficient: %f\n Salary: %f\n", pStaff->getName(), pStaff->getAge(), \
	//		*(pStaff->getBirthday()), pStaff->getID(), pStaff->getTypeStaff(), pStaff->getSalaryCoefficient(), pStaff->calSalary());

	//pStaff->~Staffs();


	//////////////////////////////////////////Static_cast///////////////////////////////////////
	//Persons* pPerson = new Persons("Pham Hoai Nguyen", 20, pBirthDay); // Ep cha thanh con
	//Students* pStudent = static_cast<Students*>(pPerson);
	//pStudent->getMSSV();
	//pStudent->getAge();

	//////////////////////////////////////////dynamic_cast/////////////////////////////////////
	//Persons* pPerson = new Persons("Pham Hoai Nguyen", 20, pBirthDay); // Ep cha thanh con(huu ich trong da ke thua)
	//Students* pStudent = dynamic_cast<Students*> (pPerson); // erro vi class cha phai co it nhat 1 ham ao
	//
	//if (pStudent)
	//{
	//	pStudent->getMSSV();
	//	pStudent->getAge();
	//	pStudent->~Students();
	//}

	////////////////////////////ep kieu con thanh cha//////////////////////////////////////////////
	//Students* pStudent = new Students("Pham Hoai Nguyen", 20, pBirthDay, 1452);
	//Persons* pPerson = pStudent;

	//pPerson->getAge();
	//pPerson->getName();
	//pPerson->~Persons();  // Neu su dung cach nay thi ham HUY cua Persons phai la virtual

	for (;;);
	return 0;

}