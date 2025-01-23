#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main() {
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        char a[20][20] = { ' ' };
//        int i = 0, j = 0;
//        for (i = 0;i < n;i++)
//        {
//            for (j = 0;j < n;j++)
//            {
//                if (i == j || i + j == (n - 1))
//                    a[i][j] = '*';
//                else
//                    a[i][j] = ' ';
//            }
//        }
//        for (i = 0;i < n;i++)
//        {
//            for (j = 0;j < n;j++)
//            {
//                printf("%c", a[i][j]);
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//
//
//void print(int num)
//{
//    int i, j;
//    for (i = 0; i < num; i++)
//    {
//        for (j = 0; j < num; j++)
//        {
//            if (i == 0 || i == num - 1 || j == 0 || j == num - 1)
//            {
//                printf("* ");
//            }
//            else
//            {
//                printf("  ");
//            }
//        }
//        printf("\n");
//    }
//}
//
//int main()
//{
//    int num;
//    while (scanf("%d", &num) != EOF)
//    {
//        print(num);
//    }
//    return 0;
//}


//
//int main() {
//    int a=0, b=0;
//    scanf("%d%d", &a, &b);
//    int i = 0, j = 0;
//    int arr1[10][10] = { 0 };
//    for (i = 0;i < a;i++)
//    {
//        for (j = 0;j < b;b++)
//        {
//            scanf("%d", &arr1[i][j]);
//        }
//    }
//    for (j = 0;j < b;j++)
//    {
//        for (i = 0;i < a;i++)
//            printf("%d ", arr1[i][j]);
//        printf("\n");
//    }
//    return 0;
//}
//int main()
//{
//    int n = 0;
//    int m = 0;
//    int arr[10][10] = { 0 };
//    scanf("%d %d", &n, &m);
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    for (i = 0; i < m; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            printf("%d ", arr[j][i]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}
//int main() {
//	int a[10] = { 0 };
//	for (int i = 0;i < 10;i++)
//		scanf("%d", &a[i]);
//	int sum = 0;
//	for (int i = 0;i < 10;i++)
//		sum += a[i];
//	float ret = sum / 10.0;
//	printf("%f", ret);
//	return 0;
//}
//int main()
//{
//	int a[10] = { 0 };
//	int b[10] = { 0 };
//	int i = 0,tmp = 0;
//	for (i = 0;i < 10;i++)
//		scanf("%d", &a[i]);
//	for (i = 0;i < 10;i++)
//		scanf("%d", &b[i]);
//	for (i = 0;i < 10;i++)
//	{
//		tmp = a[i];
//		a[i] = b[i];
//		b[i] = tmp;
//	}
//	for (i = 0;i < 10;i++)
//		printf("%d ", a[i]);
//	printf("\n");
//	for (i = 0;i < 10;i++)
//		printf("%d ", b[i]);
//	return 0;
//}

extern a;
int main()
{
	int ret = 2 * a;
	printf("%d", ret);
	return 0;
}





