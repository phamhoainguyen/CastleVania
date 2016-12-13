#include<stdio.h>
 
void main()
{
	int n = 4;
	while (--n >= 0)
		printf("%d", n);
	printf("%d", n);
	for (;;);
}