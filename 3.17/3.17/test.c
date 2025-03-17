#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
int main()
{
	SeqList SL;
	SeqListInit(&SL);
	SeqListPushBack(&SL, 1);
	SeqListPushBack(&SL, 2);
	SeqListPushBack(&SL, 3);
	SeqListPushBack(&SL, 4);
	SeqListPushBack(&SL, 5);
	SeqListPushFront(&SL, 6);
	SeqListPrint(&SL);
	SeqListInsert(&SL, 2, 7);
	SeqListPrint(&SL);
	SeqListErase(&SL, 2);
	SeqListPrint(&SL);
	SeqListDestroy(&SL);
	return 0;
}