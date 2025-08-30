#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
//void Func(int a = 0)
//{
//	cout << a << endl;
//}
////int main()
////{
////	Func(1);
////	Func();
////}
//
//void Func1(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//// 半缺省 
//
//void Func2(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	Func1();
//	Func1(1);
//	Func1(1, 2);
//	Func1(1, 2, 3);
//	Func2(100);
//	Func2(100, 200);
//	Func2(100, 200, 300);
//	return 0;
//}


////////////////////////////////////////////////////////
//引用
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//
//int main()
//{
//
//	int x = 1;
//	int y = 2;
//	swap(x, y);
//	cout << x << " " << y;
//	return 0;
//
//
//	const int& ra = 30;
//}
////不能传引用返回实例

//
//int& func(int x, int y)
//{
//	int ret = x + y * 10;
//	return ret;
//}
//
//
//int main()
//{
//	double b = 0.1;
//	int d = b;//支持隐式类型转换
//	//int& rd  = b; //常性，用const引用
//	return 0;
//}

int main()
{
	const int a = 0;
	int* ptr = &a;
	//报错是由于&a的类型是const int* 在这里权限放大
}