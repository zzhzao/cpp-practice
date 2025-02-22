#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//1
//
//1 1
//
//1 2 1
//
//1 3 3 1
//int main()
//{
//	int arr[9][9] = {1};
//	int i = 0;
//	int j = 0;
//	for (i = 1;i < 9;i++)
//	{
//		for (j = 1;j < 9;j++)
//		{
//			arr[i][0] = 1;
//			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//		}
//	}
//	for (i = 0;i < 9;i++)
//	{
//		for (j = 0;j <= i;j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//
//编写一个函数找出这两个只出现一次的数字。
//
//
//
//例如：
//
//有数组的元素是：1，2，3，4，5，1，2，3，4，6
//
//只有5和6只出现1次，要找出5和6.


//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
//	int i, j;
//	int tmp = 0;
//	int count = 0;
//	for (i = 0;i < 10;i++)
//	{
//		tmp = arr[i];
//		count = 0;
//		for (j = 0;j < 10;j++)
//		{
//			if (tmp == arr[j])
//				count++;
//		}
//		if (count != 2)
//			printf("%d ", arr[i]);
//	}
//	return 0;
//}

//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

//
//int main()
//{
//    char killer;
//    for (killer = 'A'; killer <= 'D'; killer++) {
//        // 分别表示A、B、C、D的供词真假情况
//        int a = (killer != 'A');
//        int b = (killer == 'C');
//        int c = (killer == 'D');
//        int d = (killer != 'D');
//
//        if ((a + b + c + d) == 3)
//        {
//            printf("%c", killer);
//            break;
//        }
//
//    }
//	return 0;
//}

int findnum(int a[][3], int x, int y, int f) //第一个参数的类型需要调整
{
	int i = 0, j = y - 1; //从右上角开始遍历
	while (j >= 0 && i < x)
	{
		if (a[i][j] < f) //比我大就向下
		{
			i++;
		}
		else if (a[i][j] > f) //比我小就向左
		{
			j--;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int a[][3] = { {1, 3, 5},
				  {3, 5, 7},
				  {5, 7, 9} }; //一个示例

	if (findnum(a, 3, 3, 2))
	{
		printf("It has been found!\n");
	}
	else
	{
		printf("It hasn't been found!\n");
	}

	return 0;
}