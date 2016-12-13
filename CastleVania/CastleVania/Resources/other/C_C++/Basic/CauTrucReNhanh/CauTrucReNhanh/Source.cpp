#include "stdio.h"
//
////--------------BAI 1-------------
//
//int FindMax(int a, int b, int c, int d)
//{
//	return (((((a > b) ? a : b) > c) ? ((a > b) ? a : b) : c) > d) ? ((((a > b) ? a : b) > c) ? ((a > b) ? a : b) : c) : d;
//}
//
//int FindMin(int a, int b, int c, int d)
//{
//	return (((((a < b) ? a : b) < c) ? ((a < b) ? a : b) : c) < d) ? ((((a < b) ? a : b) < c) ? ((a < b) ? a : b) : c) : d;
//}
//
//void FindMedium(int a, int b, int c, int d)
//{
//	int _max = FindMax(a, b, c, d); 
//	int _min = FindMin(a, b, c, d);
//	
//	int _center1 = _max;
//	int _center2 = _min;
//	
//	if (a < _max && b > _min || a > _min && b < _max)
//	{
//		_center1 = a;
//		_center2 = b;
//	}
//	
//	if (a < _max && c > _min || a > _min && c < _max)
//	{
//		_center1 = a;
//		_center2 = c;
//	}
//	
//	if (a < _max && d > _min || a > _min && d < _max)
//	{
//		_center1 = a;
//		_center2 = d;
//	}
//	if (b < _max && c > _min || b > _min && c < _max)
//	{
//		_center1 = b;
//		_center2 = c;
//	}
//
//	if (b < _max && d > _min || b > _min && d < _max)
//	{
//		_center1 = b;
//		_center2 = d;
//	}
//
//	if (c < _max && d > _min || c > _min && d < _max)
//	{
//		_center1 = c;
//		_center2 = d;
//	}
//
//	printf("Hai so can tim la:  %d va %d", _center1, _center2);
//}
//
////-------------BAI 7---------------
//
//bool checkYear(int _year)
//{
//	if ((_year % 4 == 0 && _year % 100 == 0) || _year % 400 == 0)
//		return true;
//	return false;
//}
//
//bool checkDateMonthYear(int _date, int _month, int _year)
//{
//	switch (_month)
//	{
//		case 1:
//		case 3:
//		case 5:
//		case 7:
//		case 8:
//		case 10:
//		case 12:
//		{
//				   if (_date >= 1 && _date <= 31)
//					   return true;
//				   return false;
//				   break;
//		}
//		case 4:
//		case 6:
//		case 9:
//		case 11:
//		{
//				   if (_date >= 1 && _date <= 30)
//					   return true;
//				   return false;
//		}
//		case 2:
//		{
//				  if (checkYear(_year))
//				  {
//					  if (_date >= 1 && _date <= 29)
//						  return true;
//					  return false;
//				  }
//				  else
//				  {
//					  if (_date >= 1 && _date <= 28)
//						  return true;
//					  return false;
//				  }
//		}
//		default:
//			return false;
//	}
//}
//
//void nextDay(int _date, int _month, int _year)
//{
//	if (checkDateMonthYear(_date, _month, _year))
//	{
//		switch (_month)
//		{
//			case 1:
//			case 3:
//			case 5:
//			case 7:
//			case 8:
//			case 10:
//			{
//					   if (_date == 31)
//					   {
//						   _date = 1;
//						   _month += 1;
//					   }
//					   else
//						   _date += 1;
//					   break;
//			}
//			case 12:
//			{
//					   if (_date == 31)
//					   {
//						   _date = 1;
//						   _month = 1;
//						   _year += 1;
//					   }
//					   else
//						   _date += 1;
//					   break;
//			}
//
//			case 4:
//			case 6:
//			case 9:
//			case 11:
//			{
//					   if (_date == 30)
//					   {
//						   _date = 1;
//						   _month += 1;
//					   }
//					   else
//						   _date += 1;
//					   break;
//			}
//			case 2:
//			{
//					  if (checkYear(_year))
//					  {
//						  if (_date == 29)
//						  {
//							  _date = 1;
//							  _month += 1;
//						  }
//						  else
//							  _date += 1;
//					  }
//					  else
//					  {
//						  if (_date == 28)
//						  {
//							  _date = 1;
//							  _month += 1;
//						  }
//						  else
//							_date += 1;
//					  }
//					  break;
//			}
//			default:
//				break;
//		}
//		printf("\nNgay ke tiep la: Ngay %d, thang %d, nam %d.", _date, _month, _year);
//	}
//	else
//	{
//		printf("\nKhong the tinh do ngay nhap vao khong dung!");
//	}
//}
//
//
//void preDay(int _date, int _month, int _year)
//{
//	if (checkDateMonthYear(_date, _month, _year))
//	{
//		switch (_month)
//		{
//		case 1:
//		{
//				  if (_date == 1)
//				  {
//					  _date = 31;
//					  _month = 12;
//					  _year -= 1;
//				  }
//				  else
//					  _date -= 1;
//				  break;
//		}
//
//		case 2:
//		case 4:
//		case 6:
//		case 9:
//		case 11:
//		{
//				   if (_date == 1)
//				   {
//					   _date = 31;
//					   _month -= 1;
//				   }
//				   else
//					   _date -= 1;
//				   break;
//
//		}
//
//		case 3:
//		{
//				  if (checkYear(_year))
//				  {
//					  if (_date == 1)
//					  {
//						  _date = 29;
//						  _month -= 1;
//					  }
//					  else
//						  _date -= 1;
//				  }
//				  else
//				  {
//					  if (_date == 1)
//					  {
//						  _date = 28;
//						  _month -= 1;
//					  }
//					  else
//						  _date -= 1;
//				  }
//				  break;
//		}
//		case 5:
//		case 7:
//		case 8:
//		case 10:
//		case 12:
//		{
//				   if (_date == 1)
//				   {
//					   _date = 30;
//					   _month -= 1;
//				   }
//				   else
//					   _date -= 1;
//				   break;
//		}
//		default:
//			break;
//		}
//		printf("\nNgay truoc do la: Ngay %d, thang %d, nam %d.", _date, _month, _year);
//	}
//	else
//	{
//		printf("\nKhong the tinh do ngay nhap vao khong dung!");
//	}
//}
//
//
//
//
//int main()
//{
//	//printf("MAX %d = ", FindMin(4, 1, 8, 3));
//	//FindMedium(1, 2, 3, 4);
//	//if (checkDateMonthYear(29, 2, 1990))
//	//	printf("Ngay hop le.");
//	//nextDay(28, 2, 1990);
//	//preDay(1, 3, 1990);
//
//	for (;;);
//	return 0;
//}
int CheckMonth(int month)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 0;
	else
	{
		if (month == 4 || month == 6 || month == 9 || month == 11)
			return 1;
		else
		{
			if (month == 2)
				return 2;
			else
				return 3;
		}
	}

}

int CheckYear(int year)
{
	if (year < 0)
	{
		return 0;
	}
	else
	{
		if ((year % 4 == 0) || (year % 100 == 0))
			return 1;
		else
			return 2;
	}
}

int CheckDay(int day, int month, int year)
{
	if (CheckMonth(month) == 0)
	{
		if (day < 0 || day > 31)
			return 0;
		else return 4;
	}
	else
	{
		if (CheckMonth(month) == 1)
		{
			if (day < 0 || day > 30)
				return 1;
			else return 4;
		}
		else
		{
			if (CheckMonth(month) == 2)
			{
				if (CheckYear(year) == 1)
				{
					if (day < 0 || day > 29)
						return 2;
					else return 4;
				}
				else
				{
					if (CheckYear(year) == 2)
					{
						if (day < 0 || day > 28) return 3;
						else return 4;
					}
				}
			}
		}
	}
}
int main()
{
	int day, month, year;
	printf("Nhap vao ngay: "); scanf_s("%d", &day);
	printf("Nhap vao thang: "); scanf_s("%d", &month);
	printf("Nhap vao nam: "); scanf_s("%d", &year);

	int checkday = CheckDay(day, month, year);
	int checkmonth = CheckMonth(month);
	int checkyear = CheckYear(year);

	if (checkyear == 0) printf("Nam khong hop le\n");
	else
	{
		if (checkmonth == 3) printf("Thang khong hop le\n");
		else
		{
			if (checkday == 0 || checkday == 1 || checkday == 2 || checkday == 3) printf("Ngay khong hop le\n");
			else
			{
				if (checkmonth == 2)
				{
					if (checkyear == 1)
					{

						printf("Thang co 29 ngay\n");
						if (day == 29)
						{
							printf("Ngay ke tiep: 1 thang 3\n");
							printf("Ngay hom truoc: 28 thang 2\n");
						}
						else
						{
							if (day == 1)
							{

								printf("Ngay ke tiep: %d thang 2\n", day + 1);
								printf("Ngay hom truoc: 31 thang 1 nam %d\n", year - 1);
							}
							else
							{

								printf("Ngay ke tiep: %d thang 2\n", day + 1);
								printf("Ngay hom truoc: %d thang 2\n", day - 1);
							}
						}
					}
					else
					{

						if (checkyear == 2)
						{

							printf("Thang co 28 ngay");
							if (day == 28)
							{
								printf("Ngay ke tiep: 1 thang 3\n");
								printf("Ngay hom truoc: 27 thang 2\n");
							}
							else
							{
								if (day == 1)
								{

									printf("Ngay ke tiep: %d thang 2\n", day + 1);
									printf("Ngay hom truoc: 31 thang 1\n");
								}
								else
								{

									printf("Ngay ke tiep: %d thang 2\n", day + 1);
									printf("Ngay hom truoc: %d thang 2\n", day - 1);
								}
							}
						}
					}
				}
				else
				{


					if (checkmonth == 0)
					{

						printf("Thang co 31 ngay");
						if (day == 1 && month == 1)
						{
							printf("Ngay ke tiep : %d thang 1\n", day + 1);
							if (year == 1)
							{
								printf("Khong xac dinh duoc ngay hom truoc\n");
							}
							else
								printf("Ngay hom truoc: 31 thang 12 nam %d\n", year - 1);
						}
						else
						{
							if (day == 31 && month == 12)
							{
								printf("Ngay ke tiep: 1 thang 1 nam %d", year + 1);
								printf("Ngay hom truoc: 30 thang 12");
							}
							else
							{
								if (day == 1)
								{

									printf("Ngay 3");
								}
							}

						}
					}
					else
					{
						if (checkmonth == 1) printf("Thang co 30 ngay");
					}
				}
			}
		}
	}

	for (;;);
}
