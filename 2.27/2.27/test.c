#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//ÊµÏÖatoiº¯Êý

int my_atoi(char* str)
{
	int ret = 0;
	int sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' || *str == '\v' || *str == '\f') {
		str++;
	}

	if (*str <= '0' || *str >= '9')
	{
		if (*str == '-') {
			sign = -1;
			str++;
		}
		else if (*str == '+') {
			str++;
		}
		else
			return ret;
	}
	while ('0' <= *str && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return sign*ret;
	
}

int main()
{
	char str[] = "123";
	printf("%d",my_atoi(str));
	return 0;
}