#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
struct stu
{
	char name[20];
	int age;
};
//比较函数的自我实现,通过strcmp来比较name大小
int cmp_stu_name(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}
void swap(void* p1, void* p2, int size)
{
	//由于类型未知,所以将传过来的数据对应的字节一一调换
	for (int i = 0;i < size;i++)
	{
		char tmp = *((char*)p1 + i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}
//width为传过来参数的大小  cmp为回调函数
void bubble_sort(void* base, int num, int width, int (*cmp) (void* e1, void* e2))
{
	//调用cmp_stu_name函数,如果返回值大于0,则交换顺序
	int i = 0;
	int j = 0;
	for (i = 0;i < num;i++)
	{
		int flag = 1;//如果顺序调换,则数组还是乱序,值改为0;反正有序退出循环
		for (j = 0;j < num;j++)
		{
			//为了能够比较任意类型的数据,将base强转为char*类型进行比较
			if ((cmp((char*)base + j * width, (char*)base + (j + 1) * width)) > 0)
			{
				swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
			}
		}
	}
}

void test()
{

	struct stu arr[] = { {"zhangsan",18},{"lisi",20} };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//模仿qsort函数的参数
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_stu_name);
	for(int i = 0;i<sz;i++)
	printf("%s %d\n", arr[i].name, arr[i].age);
}

int main()
{
	test();
	return 0;
}