#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 100

void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void GenerateRandomIntArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n + 1;

	}
	Output(a, n);
}

void SubArr(int a[], int n)
{
	int i = 0;
	do
	{
		printf("%d", a[i]);
		for (int j = i + 1; j < n; j++)
		{
			i++;
			if (a[j]>a[j - 1])
			{

				printf("-%d", a[j]);

			}
			else
			{
				printf(",");
				break;
			}
		}
	} while (i < n - 1);
	if (a[n - 1] <= a[n - 2])
		printf("%d", a[n - 1]);
}

int FindMax(int a[], int n)
{
	int i = 0, count = 0, Max = 0;
	do
	{

		for (int j = i + 1; j < n; j++)
		{
			i++;
			if (a[j]>a[j - 1])
			{

				count++;

			}
			else
			{
				if (count > Max)
				{
					Max = count;
				}
				count = 0;
				break;
			}
		}
	} while (i < n - 1);
	return Max;
}

void LenghSub(int a[], int n)
{
	int i = 0, count = 0, Max = FindMax(a, n), b[max], y = 0;
	do
	{

		for (int j = i + 1; j < n; j++)
		{
			i++;
			if (a[j]>a[j - 1])
			{
				count++;
				if (count == Max)
				{
					b[y] = j;
					y++;
				}
			}
			else
			{
				count = 0;
				break;
			}
		}
	} while (i < n - 1);

	for (int i = 0; i < y; i++)
	{
		for (int j = b[i] - Max; j <= b[i]; j++)
		{
			printf("%d ", a[j]);
		}
		printf("\n");
	}
}


void main()
{
	int a[] = { 1, 2, 3, 5, 8, 2, 1, 7, 4, 9, 3, 2, 6 };
	int n = 13;

	printf("\nMang con tang: ");
	SubArr(a, n);
	LenghSub(a, n);
	for (;;);
}