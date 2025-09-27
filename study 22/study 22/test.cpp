#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>

using namespace std;


namespace Container
{
	typedef int const_iterator;

}
template<class Container>
void Print(const Container& con)
{
	typename Container::const_iterator it = con.begin();
	while (it != con.end())
	{
		cout << *it << ' ';
		++it;
	}
	cout << endl;
}
 

void test()
{
	Container::const_iterator i = 5;
	cout << "test" << endl;

}

//typename<class T>
//void Print(const vector<T>& con)
//{
//	vector<T>::const_iterator it = con.begin();
//	while (it != con.end())
//	{
//		cout << *it << ' ';
//		++it;
//	}
//	cout << endl;
//}


int main()
{
	vector<int> v = { 1,2,3,4,5 };
	//Print(v);
	test();
	return 0;
}