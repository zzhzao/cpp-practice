#define _CRT_SECURE_NO_WARNINGS 1
#include"BSTree.h"

int main()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	BSTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();
	return 0;
}