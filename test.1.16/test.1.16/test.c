#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 0;i <= 100;i++)
//	{
//		if (i % 3 == 0)
//			printf("% d", i);
//	}
//	return 0;
//}
#include<stdio.h>

int main()

{

	int a = 0, b = 0, c = 0;

	int i = 0;

	scanf("%d%d%d", &a, &b, &c);

	if (a < b)

	{
		i = a;a = b;b = i;
	}

	if (b < c)

	{
		i = b;b = c;c = i;
	}

	printf("%d %d %d", a, b, c);

	return 0;
}