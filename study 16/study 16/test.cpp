#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	//vector<string> v1;
	//v1.push_back("уехЩ");
	//v1.push_back("lisi");
	//v1.push_back("wangwu");

	vector<int> v1;

	v1.push_back(1);
	v1.push_back(6);
	v1.push_back(3);
	v1.push_back(9);
	v1.push_back(5);
	sort(v1.begin(), v1.end());

	sort(v1.begin(), v1.begin()+3);

	sort(v1.begin(), v1.end(), greater<int>());
	return 0;
}