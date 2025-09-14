#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"
using namespace std;
namespace zzh
{
	void test1()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		for (int i = 0;i < s1.size();i++)
		{
			std::cout << s1[i] << " ";
		}

		//string s1;
		//cout << s1.c_str();

	}

	void test2()
	{
		string s1("hello world");
		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			(*it)++;

			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test3()
	{
		string s1("hello world");
		//string::const_iterator it = s1.begin();
		//while (it != s1.end())
		//{
		//	//(*it)++;

		//	cout << *it << " ";
		//	++it;
		//}

		for (auto& e : s1)
		{
			cout << e << ' ';
		}
		cout << endl;
	}
	void test4()
	{
		string s1;
		s1.push_back('x');
		s1.push_back('x');
		s1.push_back('x');
		s1.push_back('x');
		for (auto e : s1)
		{
			cout << e << ' ';
		}
	}
	void test5()
	{
		string s1("hello ");
	
		s1.append("world");
		s1 += 'x';
		s1 += "xxxxxx";
		cout << s1.c_str() << endl;
	}
	void test6()
	{
		string s1("hello");
		s1 += ' ';
		s1 += "world";

		cout << s1.c_str();
	}
	void test7()
	{
		string s1("hello world");
		s1.insert(5, 'x');
		cout << s1.c_str();
	}
	void test8()
	{
		string s1("hello world");
		//s1.erase(5, 6);
		//s1.erase(5, 10);
		s1.erase(5, 2);
		cout << s1.c_str();
	}
}
int main()
{
	zzh::test8();
	return 0;
}