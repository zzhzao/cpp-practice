#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//#include<string.h>
//void swap(char arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		char a = arr[left];
//		arr[left] = arr[right];
//		arr[right] = a;
//		left++;
//		right--;
//	}
//	printf("%s", arr);
//}
//int main()
//{
//	char a [] = "hello";
//	int sz = strlen(a);
//	swap(a, sz);
//	return 0;
//}
//int add(int a, int b)
//{
//	return a + b;
//}
//int sub(int a, int b)
//{
//	return a - b;
//}
//int mul(int a, int b)
//{
//	return a * b;
//}
//int div(int a, int b)
//{
//	return a / b;
//}
//
//void menu()
//{
//	printf("**********************\n");
//	printf("*****1.add 2.sub******\n");
//	printf("*****3.mul 4.div******\n");
//	printf("********0.exit********\n");
//}
//
//int main()
//{
//	menu();
//	int input = 0;
//	scanf("%d", &input);
//	int (*p[5])(int, int) = { NULL,add,sub,mul,div };
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	int r = p[input](a, b);
//	printf("%d", r);
//	return 0;
//}
//int  reverse(char src[], int time)
//{
//	int len = strlen(src);
//	char temp[100];
//	strcpy(temp, src);  // 复制原始字符串到临时数组
//
//	for (int i = 0; i < time; i++) {  // 执行 time 次的单次平移
//		char first_char = temp[0];
//		for (int j = 0; j < len - 1; j++) {  // 单次平移
//			temp[j] = temp[j + 1];
//		}
//		temp[len - 1] = first_char;
//	}
//	if (strcmp(src, temp) == 0)
//		return 1;
//	else
//		return 0;
//}
//
//
//int main()
//{
//	char a[] = "ABCD";
//	int sz = strlen(a);
//	int r = 0;
//	for (int num = 0;num < sz;num++)
//	{
//		 r = reverse(a, num);
//		 if (r) {
//			 printf("经过 %d 次循环右移后，字符串与原始字符串相同。\n", num);
//		 }
//		 else {
//			 printf("经过 %d 次循环右移后，字符串与原始字符串不同。\n", num);
//		 }
//	}
//	return 0;
//}

//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。

