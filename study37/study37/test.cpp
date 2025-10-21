
#include<iostream>
using namespace std;

//int main()
//{
//	auto func = [](int a, int b)->int {return a + b;};
//
//	cout << func(1, 2) << endl;
//}
int x = 0;

// 捕捉列表必须为空，因为全局变量不⽤捕捉就可以⽤，没有可被捕捉的变量 

auto func1 = []()
	{
		x++;
	};

int main()
{
	// 只能⽤当前lambda局部域和捕捉的对象和全局对象 
	int a = 0, b = 1, c = 2, d = 3;
	auto func1 = [a, &b]
		{
			// 值捕捉的变量不能修改，引⽤捕捉的变量可以修改 
			//a++;

			b++;
			int ret = a + b;
			return ret;
		};
	cout << func1() << endl;
	// 隐式值捕捉 
	// ⽤了哪些变量就捕捉哪些变量 
	auto func2 = [=]
		{
			int ret = a + b + c;
			return ret;
		};
	cout << func2() << endl;
	// 隐式引⽤捕捉 
	// ⽤了哪些变量就捕捉哪些变量 
	auto func3 = [&]
		{
			a++;
			c++;
			d++;
		};
	func3();
	cout << a << " " << b << " " << c << " " << d << endl;
	// 混合捕捉1 
	auto func4 = [&, a, b]
		{
			//a++;

			//b++;

			c++;
			d++;
			return a + b + c + d;
		};
	func4();
	cout << a << " " << b << " " << c << " " << d << endl;
	// 混合捕捉1 
	auto func5 = [=, &a, &b]
		{
			a++;
			b++;
			/*c++;
			d++;*/

			return a + b + c + d;
		};
	func5();
	cout << a << " " << b << " " << c << " " << d << endl;
	// 局部的静态和全局变量不能捕捉，也不需要捕捉 
	static int m = 0;
	auto func6 = []
		{
			int ret = x + m;
			return ret;
		};
	// 传值捕捉本质是⼀种拷⻉,并且被const修饰了 
	// mutable相当于去掉const属性，可以修改了 
	// 但是修改了不会影响外⾯被捕捉的值，因为是⼀种拷⻉ 
	auto func7 = [=]()mutable

		{
			a++;
			b++;
			c++;
			d++;
			return a + b + c + d;
		};
	cout << func7() << endl;
	cout << a << " " << b << " " << c << " " << d << endl;
	return 0;
}


#include<functional>

int f(int a, int b)
{
	return a + b;
}

struct Functor

{

public:
	int operator() (int a, int b)
	{
		return a + b;
	}
};
int main()
{
	// 包装各种可调⽤对象 
	function<int(int, int)> f1 = f;
	function<int(int, int)> f2 = Functor();
	function<int(int, int)> f3 = [](int a, int b) {return a + b; };
	return 0;
}