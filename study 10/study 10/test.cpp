#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

#include<string>
#include <algorithm>
using namespace std;


//template<class T>
//class Stack
//{
//public:
//	void push(const T& x)
//	{
//
//	}
//
//private:
//	T* _a;
//	size_t _top;
//	_size_t _capacity;
//};
//
//
//int main()
//{
//
//	Stack<int> st1;
//	Stack<double> st2;
//	return 0;
//}

//class string
//{
//private:
//	char* _str;
//	size_t  _size;
//	size_t _capacity;
//};

int main()
{

	string s1 = "whoami";
	string s2("hello");
	string s3 = " world";

	string s4(s3);
	string s5(10, '#');

	string s6(s2, 2, 2);
	cout << s6 << endl;

	s6 = s1;
	s1[0] = 'a';
	cout << s1;
	cout << endl;

	for (int i = 0;i < s1.size(); i++)
	{
		s1[i]++;
	}
	cout << s1 << endl;


	string::iterator it = s1.begin();


	while (it != s1.end())
	{
		cout << *it << ' ';
		it++;
	}
	cout << endl;
	return 0;

}
