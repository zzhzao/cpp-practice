#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int fib = 1;
//	for (fib = 1;a > 0;a--)
//	{
//		fib = fib * a;
//	}
//	printf("%d", );
//	return 0;
//}

//int fib(int a)
//{
//	if (a == 1)
//		return 1;
//	else
//		return a * fib(a - 1);
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int ret = fib(a);
//	printf("%d", ret);
//	return 0;
//}

//int main()
//{
//	int a[9] = { 1,2,3,4,5,1,2,3,4 };
//	int b = 0;
//	int i = 0;
//	for (i = 8;i >= 0;i--)
//	{
//		b = b ^ a[i];
//	}
//	printf("%d", b);
//	return 0;
//}


//int main()
//{
//	int a = 5;
//	int b = 3;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d", a, b);
//	return 0;
//}

//void print(int num)
//{
//	int i = 0;
//	for (i = 31;i > 0;i -= 2)
//	{
//		int bit = (num>>i) & 1;
//		printf("%d ", bit);
//	}
//	printf("\n");
//	for (i = 30;i > 0;i -= 2)
//	{
//		int bit = (num>>i) & 1;
//		printf("%d ", bit);
//	}
//}
//int main()
//{
//	int num = 15;
//	print(num);
//	return 0;
//}



int main()
{
	int a = 1999;
	int b = 2299;
	int i = 0;
	int count = 0;
	int m = 0, n = 0;
	for (i = 0;i < 32;i++)
	{
		n = (a >> i) & 1;
		m = (b >> i) & 1;
		if (n != m)
			count++;
	}
	printf("%d", count);
	return 0;
}