#include <stdio.h>

int main()
{
	/*FILE *f = fopen("SoNguyen", "w");
	for (int i = 0; i < 256; i++)
		_putw(i, f);
	fclose(f);

	int i;
	f = fopen("SoNguyen", "r");
	while ((i = _getw(f)) != EOF)
	{
		printf("\t %d", i);
	}
	fclose(f);*/

	/*FILE *f1 = fopen("File1.txt", "rb");
	FILE *f2 = fopen("File2.txt", "wb");

	int n;
	char c[1000];
	if (f1 == NULL)
		printf("Can't open file!");
	
	while ((n = fread(c, 1, 1000, f1)) > 0)
	{
		fwrite(c, 1, n, f2);
	}
	fclose(f1);
	fclose(f2);*/
	int d = 10;
	printf("%f",d);

	return 0;
}