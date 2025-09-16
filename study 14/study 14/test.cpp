#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

void test1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	
	for (int i = 0;i < v1.size();i++)
	{
		cout << v1[i] << ' ';
	}
	cout << endl;

	vector<int>::iterator it1 = v1.begin();

	v1.insert(v1.begin(), 0);



	for (int i = 0; i < v1.size(); i++)
	{
		cout << *(it1 + i) << ' ';
	}
	cout << endl;
	for (auto e : v1)
	{
		cout << e << ' ';
	}
	cout << endl;
}

void test2()
{
	vector<int> v1 = { 1,2,3,4,5,6,7 };

}
int main()
{
	test1();
	return 0;
}