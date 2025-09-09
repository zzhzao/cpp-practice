#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class Date
//
//{
//
//public:
//	Date(int& x,int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_n(1)
//		,ret(x)
//	{
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//
//	const int _n;
//	int& ret;
//};
//
//
//
//
//int main()
//{
//	return 0;
//}


class A

{

public:
	// 构造函数explicit就不再⽀持隐式类型转换 
	// explicit A(int a1)

	A(int a1)
		:_a1(a1)
	{
	}
	//explicit A(int a1, int a2)

	A(int a1, int a2)
		:_a1(a1)
		, _a2(a2)
	{
	}
	void Print()
	{
		cout << _a1 << " " << _a2 << endl;
	}
		int Get() const

	{
		return _a1 + _a2;
	}

private:
	int _a1 = 1;
	int _a2 = 2;
};

class B

{

public:
	B(const A& a)
		:_b(a.Get())
	{
	}

private:
	int _b = 0;
};

int main()
{
	//构造
	A aa(1);
	//隐式类型转换
	A aa1 = 1;



	const A& aa2 = 1;
	A& aa3 = 1;


}
 