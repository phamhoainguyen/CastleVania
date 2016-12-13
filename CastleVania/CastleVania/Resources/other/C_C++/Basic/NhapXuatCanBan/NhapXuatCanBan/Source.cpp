#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int totalSeconds();
void TinhTienTaXi(int km);
void totalHours();

int main()
{
	//printf("\n Tong so giay la: %d", totalSeconds());
	//printf("%d", (-7) % 2);
	//totalHours();
	TinhTienTaXi(60);
	for (;;);
	return 0;
}

int totalSeconds()
{
	int _hours, _minutes, _seconds;

	printf("\nNhap so gio: ");
	scanf("%d", &_hours);

	printf("\nNhap so phut: ");
	scanf("%d", &_minutes);

	printf("\nNhap so giay: ");
	scanf("%d", &_seconds);

	int _totalSeconds = (_hours * 3600) + (_minutes * 60) + _seconds;
	return _totalSeconds;
}

void totalHours()
{
	int _totalSeconds;

	printf("\nNhap so giay: ");
	scanf("%d", &_totalSeconds);

	printf("\nSo gio la: %d",	_totalSeconds / 3600);
	printf("\nSo phut la: %d", (_totalSeconds % 3600) / 60);
	printf("\nSo giay la: %d", (_totalSeconds % 3600) % 60);
}

void TinhTienTaXi(int km)
{
	int Money;
	if (0 < km && km <= 1)
		Money = km * 5000;
	if (km > 1 && km <= 5)
		Money = km * 4500 + 500;
	if (km > 5 && km <= 120)
		Money = km * 3500 + 5500;
	if (km > 120)
		printf("So tien phai tra la: %d\n", Money);
}