#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void SeqListInit(SeqList* ps)
{
	SLDateType* tmp =(SLDateType*) malloc(4 * sizeof(SLDateType));
	if (tmp == NULL)
	{
		perror("malloc failed:");
		exit(1);
	}
	ps->a = tmp;
	ps->capacity = 4;
	ps->size = 0;
}
void SeqListDestroy(SeqList* ps)
{
	assert(ps->a);
	ps->capacity = ps->size = 0;
	free(ps->a);
	ps->a = NULL;
}
void SeqListPrint(SeqList* ps)
{

	int num = ps->size;
	SLDateType* cur = ps->a;
	while (num--)
	{
		printf("%d ",*cur++);
	}
	printf("\n");
}
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps->a);
	if (ps->capacity == ps->size)
	{
		SLDateType* tmp = (SLDateType*)realloc(ps->a,sizeof(SLDateType) * 2 * (ps->capacity));
		assert(tmp);
		ps->a = tmp;
		ps->capacity *= 2;
	}
	ps->a[ps->size++] = x;
}
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps->a);
	if (ps->capacity == ps->size)
	{
		SLDateType* tmp = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * 2 * (ps->capacity));
		assert(tmp);
		ps->a = tmp;
		ps->capacity *= 2;
	}
	int num = ps->size;
	while (num)
	{
		ps->a[num] = ps->a[num - 1];
		num--;
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopFront(SeqList* ps)
{
	assert(ps->a);
	for (int i = 0;i < ps->size - 1;i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
void SeqListPopBack(SeqList* ps)
{
	assert(ps->a);
	ps->size--;
}
int SeqListFind(SeqList* ps, SLDateType x)
{
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	assert(ps->a);
	if (ps->capacity == ps->size)
	{
		SLDateType* tmp = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * 2 * (ps->capacity));
		assert(tmp);
		ps->a = tmp;
		ps->capacity *= 2;
	}
	int num = ps->size;
	for (;num > pos;num--)
	{
		ps->a[num] = ps->a[num - 1];
	}
	ps->a[pos] = x;
}
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps->a);
	for (int cur = pos;pos < (ps->size);cur++)
	{
		ps->a[pos] = ps->a[pos + 1];
	}
	ps->size--;

}