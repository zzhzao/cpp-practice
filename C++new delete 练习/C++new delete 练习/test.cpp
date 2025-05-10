#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
void test()
{
	int* ptr1 = new int;
	int* ptr2 = new int(10);
	int* ptr3 = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	delete ptr1;
	delete ptr2;
	delete[] ptr3;
}
class A
{
private:
	int _a;
};
void test1()
{
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = new A();
	free(p1);
	delete p2;
}
int main()
{
	test();
	test1();
	return 0;
}