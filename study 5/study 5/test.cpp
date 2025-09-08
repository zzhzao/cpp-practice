#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

//class Date
//
//{
//
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//
//	int _year;
//	int _month;
//	int _day;
//};
//
//bool operator==(const Date& d1,const Date& d2)
//{
//	return d1._year == d2._year && d2._month == d1._month && d1._day == d2._day;
//}
//int main()
//{
//	int i = 0;
//	++i;
//
//	Date d1(2025,9,8);
//	Date d2(2025,9,10);
//	if (d1 == d2)
//	{
//		printf("=");
//	}
//	if (operator==(d1, d2))
//	{
//		cout << " = " << endl;
//	}
//	//bool ret = d1 < d2;
//
//
//	return 0;
//}
//
//class Date
//
//{
//
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	bool operator==(const Date& d1)
//	{
//		return d1._year == _year && _month == d1._month && d1._day == _day;
//	}
//	//日期-日期
//	int operator-(const Date& d);
//	//日期-天数
//	Date operator-(int day);
//
//
//	//前置
//	Date operator++();
//	//后置 int无任何意义只为了区分
//	Date operator++(int);
//
//
//private:
//
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	int i = 0;
//	++i;
//
//	Date d1(2025, 9, 8);
//	Date d2(2025, 9, 10);
//	Date d3(2025, 9, 10);
//	if (d1 == d2)
//	{
//		printf("=");
//	}
//	if (d3.operator==(d2))
//	{
//		cout << " = " << endl;
//	}
//	//bool ret = d1 < d2;
//
//
//	return 0;
//}
//
//
//class seqlist
//{
//public:
//	seqlist(int n = 4)
//	{
//		_a = (int*)malloc(sizeof(int)*n);
//		_size = 0;
//		_capacity = n;
//	}
//	~seqlist()
//	{
//		free(_a);
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//	void pushback(int x)
//	{
//		//扩容
//		_a[_size++] = x;
//	}
//	int size()
//	{
//		return _size;
//	}
//	int& operator[](int x)
//	{
//		return _a[x];
//	}
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	seqlist s;
//	s.pushback(1);
//	s.pushback(2);
//	s.pushback(3);
//
//	for (int i = 0; i < s.size();i++)
//	{
//		//s[i] += 10;
//		cout << s[i] << " ";
//	}
//
//	cout << endl;
//	return 0;
//
//}

//class A
//
//{
//
//public:
//	void func()
//	{
//		cout << "A::func()" << endl;
//	}
//};
//
//typedef void(A::* PF)(); //成员函数指针类型 
//
//int main()
//{
//	PF pf = &A::func;
//	A obj;
//	(obj.*pf)();
//}

////////////////////////////////////////////////////////////
class Date

{

public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//bool operator==(const Date& d1)
	//{
	//	return d1._year == _year && _month == d1._month && d1._day == _day;
	//}
	////日期-日期
	//int operator-(const Date& d);
	////日期-天数
	//Date operator-(int day);


	////前置
	//Date operator++();
	////后置 int无任何意义只为了区分
	//Date operator++(int);


	//Date& operator=(const Date& d)
	//{
	//	if (this != &d)
	//	{
	//		_year = d._year;
	//		_month = d._month;
	//		_day = d._day;
	//	}
	//	return *this;
	//}


private:

	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d0;
	Date d1(2025, 9, 8);
	Date d2(2025, 9, 10);

	d1 = d2;
	d1.Print();
	d2.Print();

	d0 = d2 = d1;
	d0.Print();

	//拷贝构造
	Date d3 = d2;
	Date d4(d2);
	//下面的写法的可读性更强，所以cpp有=的拷贝构造
	Date ret1(d1 + 100);
	Date ret2 = d1 + 100;

	return 0;
}