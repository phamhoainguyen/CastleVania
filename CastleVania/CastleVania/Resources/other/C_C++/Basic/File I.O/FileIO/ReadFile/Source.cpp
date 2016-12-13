#include "stdio.h"



int main()
{

	// Sao chep file
	/*char c;
	FILE	*_file_1 = fopen("STDIO.txt", "r+");
	FILE	*_file_2 = fopen("Training.txt", "w+");
	if (_file_1 == NULL)
	{
	printf("Can't open file!");
	}
	while (c = getc(_file_2) != EOF)
	{
	printf("%c", c);
	putc(c, _file_1);
	}
	fclose(_file_1);
	fclose(_file_2);*/
	

	//Tao file voi ham fprintf
	/*FILE *f;

	f = fopen("fprintf.txt", "wt");
	fprintf(f, "Cac dong");
	for (int i = 0; i < 5; i++)
	{
	fprintf(f, "\nDong thu %d", i);
	}
	fclose(f); */

	//Đọc file với  fscanf
	/*FILE *f;
	int n;
	int x[10], y[10];
	f = fopen("fscanf.txt", "rt");
	fscanf(f, "So dinh %d", &n);
	for (int i = 0; i <= n; i++)
	{
	fscanf(f, " %4d %4d", &x[i], &y[i]);
	}
	printf("%d", n);
	fclose(f);*/

	/*FILE *f = fopen("number.txt", "r");
	FILE *f2 = fopen("writeNumber.txt", "w");
	int n;
	if (f == NULL)
	printf("Can't open file! ");
	while (!feof(f));
	{
	fscanf(f, "%d", &n);
	fprintf(f2,"%2d", n);
	}
	fclose(f);
	fclose(f2);*/

	/*char d[256];
	int i = 0;
	FILE *f = fopen("dong_vb", "w");
	for (int j = 0; j < 3; j++)
	{
		++i;
		printf("\nDong %d: ", i);
		gets(d);
		fputs(d, f);
	}
	fclose(f);*/


	/*char d[256];
	int i = 0;
	FILE *f = fopen("dong_vb", "r");
	FILE *f2 = fopen("ghi_vb", "w");
	while(!feof(f))
	{
		++i;
		fgets(d, 256,f);
		printf("\nDong %d: %s", i, d);
		fputs(d, f2);
	}
	fclose(f);
	fclose(f2);*/

		

	return 0;
}


void readFile(const char* FilePath, char *&buff, long &fileSize)
{
	FILE *pFile = fopen(FilePath, "rb");

	if (pFile == NULL)
	{
		return;
	}

	fseek(pFile, 0, SEEK_END);
	fileSize = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);

	if (buff != NULL)
	{
		delete[] buff;
	}

	buff = new char[fileSize];
	fread(buff, fileSize, 1, pFile);
	fclose(pFile);
}