#include<iostream>
using namespace std;
//
//void ShowList()
//{
//	// 编译器时递归的终⽌条件，参数包是0个时，直接匹配这个函数 
//	cout << endl;
//}
//
//template <class T, class ...Args>
//
//void ShowList(T x, Args... args)
//{
//	if (sizeof...(args) == 0)
//		return;
//	cout << x << " ";
//	ShowList(args...);
//}
//
//// 编译时递归推导解析参数 
//
//template <class ...Args>
//
//void Print(Args... args)
//{
//	ShowList(args...);
//}
//
//int main()
//{
//	Print();
//	Print(1);
//	Print(1, string("xxxxx"));
//	Print(1, string("xxxxx"), 2.2);
//	return 0;
//}template <class T>

const T& GetArg(const T& x)
{
	cout << x << " ";
	return x;
}

template <class ...Args>

void Arguments(Args... args)
{
}

template <class ...Args>

void Print(Args... args)
{
	// 注意GetArg必须返回或者到的对象，这样才能组成参数包给Arguments 
	Arguments(GetArg(args)...);
}

//void Print(int x, string y, double z)
//{
// Arguments(GetArg(x), GetArg(y), GetArg(z));
//}

int main()
{
	Print(1, string("xxxxx"), 2.2);
	return 0;
}