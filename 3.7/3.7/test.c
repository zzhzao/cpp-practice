#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"
int main()
{
	SLT ps;
	seqlistInit(&ps);
	seqlistpushback(&ps, 1);
	seqlistpushback(&ps, 2);
	seqlistpushback(&ps, 3);
	seqlistpushback(&ps, 4);
	seqlistpushback(&ps, 5);
	seqlistprint(&ps);
	seqlistpushfront(&ps, 6);
	seqlistprint(&ps);
	seqlistpopback(&ps);
	seqlistprint(&ps);
	seqlistdestroy(&ps);
	return 0;
}