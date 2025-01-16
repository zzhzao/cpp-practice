#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int ret= scanf("%d%d", &a, &b);
	printf("%d", ret);
	return 0;
}