#define _CRT_SECURE_NO_WARNINGS 1
#include"vector.h"
using namespace std;
namespace zzh
{
	void test1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(3);
		v1.push_back(5);
		v1.push_back(2);
		v1.push_back(4);
		v1.push_back(9);
		auto it = find(v1.begin(), v1.end(), 3);
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;
		v1.erase(it);
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

	}
	void test2()
	{
		vector<int> v{ 1,2,3,4,5 };
		// vector<int> v{1,2,3,4,5,6};

		auto it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
				v.erase(it);
			++it;
		}
		for (auto e : v)
			cout << e << " ";
		cout << endl;
	}
	void test3()
	{
		vector<string> v1;
		v1.push_back("111111111111111111111");
		v1.push_back("111111111111111111111");
		v1.push_back("111111111111111111111");
		v1.push_back("111111111111111111111");
		v1.push_back("111111111111111111111");

		for (auto& e : v1)
		{
			cout << e << " ";
		}
	}
}
int main()
{
	zzh::test3();
	return 0;
}