#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	FILE* pr = fopen("data.txt", "r");
	if (pr == NULL)
	{
		perror("fopen for read");
		return 1;
	}
	FILE* pw = fopen("data_copy.txt", "w");
	if (pw == NULL)
	{
		perror("fopen for write");
		return 1;
	}
	int ch = 0;
	while ((ch = fgetc(pr)) != EOF)
	{
		fputc(ch, pw);
	}
	fclose(pr);
	fclose(pw);
	pr = NULL;
	pw = NULL;
	return 0;
}