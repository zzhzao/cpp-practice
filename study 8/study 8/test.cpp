#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

//int main()
//{
//	int* ptr1 = new int(1);
//	int* ptr2 = new int[10];
//
//	delete ptr1;
//
//	delete[] ptr2;
//
//	return 0;
//}

struct listnode
{
	int _val;
	listnode* _next;
	listnode(int val)
		:_val(val)
		,_next(nullptr)
	{

	}
};
template<class T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
T ADD(T a, T b)
{
	return a + b;
}
int main()
{

	listnode* node1 = new listnode(1);
	listnode* node2 = new listnode(2);
	listnode* node3 = new listnode(3);
	listnode* node4 = new listnode(4);


	int x = 1;
	int y = 2;
	Swap(x, y);

	cout << x << " " << y << endl;
	cout << ADD(x, y);
	return 0;
}