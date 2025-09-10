#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class A
//{
//public:
//	A(int i = 0)
//	{
//		x = i;
//		++_scount;
//	}
//	A(const A& t)
//	{
//		++_scount;
//	}
//	static int getcount()
//	{
//		return _scount;
//	}
//private:
//	static int _scount;
//	int x;
//};
//int A::_scount = 0;
//
//int main()
//{
//
//	//A a1;
//	////公有时
//	//a1._scount;
//	//A::_scount;
//	////私有公有时
//	//a1.getcount();
//	return 0;
//}


//
//
//class Date
//{
//	ostream& operator<<(ostream& out)
//	{
//		out << _year;
//	}
//
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//private:
//	int _year;
//};
//
//inline ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year;
//}
//inline istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year;
//}
//
//void test1()
//{
//	int i = 0;
//	cout << i;
//	cout.operator<<(i);
//
//	cout << i << " " << endl;
//}
//int main()
//{
//
//	test1();
//	return 0;
//}

//
//
//class A
//
//{
//
//private:
//	static int _k;
//	int _h = 1;
//
//public:
//	class B // B默认就是A的友元 
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << _k << endl; //OK
//
//			cout << a._h << endl; //OK
//
//		}
//
//		int _b1;
//	};
//};
//
//int A::_k = 1;
//
//int main()
//{
//	cout << sizeof(A) << endl;
//
//
//		A::B b;
//	A aa;
//	b.foo(aa);
//	return 0;
//}



class A

{

public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}

private:
	int _a;
};
class Solution {

public:
	int Sum_Solution(int n) {
		//...

		return n;
	}
};

int main()
{
	A aa1;
	// 不能这么定义对象，因为编译器⽆法识别下⾯是⼀个函数声明，还是对象定义 
	//A aa1();

	// 但是我们可以这么定义匿名对象，匿名对象的特点不⽤取名字， 
	// 但是他的⽣命周期只有这⼀⾏，我们可以看到下⼀⾏他就会⾃动调⽤析构函数 
	A();
	A(1);
	A aa2(2);
	// 匿名对象在这样场景下就很好⽤，当然还有⼀些其他使⽤场景，这个我们以后遇到了再说 
	Solution().Sum_Solution(10);
	return 0;
}
