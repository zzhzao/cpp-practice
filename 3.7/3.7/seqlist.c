#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"
void seqlistInit(SLT* slt)
{
	slt->a = NULL;
	slt->size = 0;
	slt->capacity = 0;
}
void seqlistdestroy(SLT* slt)
{
	free(slt->a);
	slt->a = NULL;
	slt->size = 0;
	slt->capacity = 0;
}
void seqlistCheckCapacity(SLT* slt)
{
	if (slt->capacity == slt->size)
	{
		int newcapacity = (slt->capacity == 0) ? 4 : slt->capacity * 2;
		SLTdatatype* tmp = (SLTdatatype*)realloc(slt->a,sizeof(SLTdatatype) * newcapacity);
		if (tmp == NULL)
		{
			printf(" realloc failed\n");
			exit(-1);
		}
		else
		{
			slt->a = tmp;
			slt->capacity = newcapacity;
		}
	}
}

void seqlistprint(SLT* slt)
{
	for (int i = 0; i <slt->size; ++i)
	{
		printf("%d ", slt->a[i]);
	}
	printf("\n");
}

void seqlistpushback(SLT* slt,SLTdatatype x)
{
	seqlistCheckCapacity(slt);
	slt->a[slt->size] = x;
	slt->size++;
}

void seqlistpushfront(SLT* slt, SLTdatatype x)
{
	seqlistCheckCapacity(slt);
	int cur = slt->size;
	while (cur)
	{
		slt->a[cur] = slt->a[cur - 1];
		cur--;
	}
	slt->a[cur] = x;
	slt->size++;
}

void seqlistpopback(SLT* slt)
{
	assert(slt->size > 0);
	slt->a[slt->size - 1] = 0;
	slt->size--;
}

void seqlistpopfront(SLT* slt)
{
	assert(slt->size > 0);
	int cur = 1;
	while (cur < slt->size)
	{
		slt->a[cur - 1] = slt->a[cur];
		cur++;
	}
	slt->size--;
}

void seqlistInsert(SLT* slt, int pos, SLTdatatype x)
{
	assert(pos <= slt->size);
	seqlistCheckCapacity(slt);

	int end = slt->size - 1;
	while (end >= pos)
	{
		slt->a[end + 1] = slt->a[end];
		end--;
	}
	slt->a[pos] = x;
	slt->size++;
}

void seqlistpop(SLT* slt, int pos)
{
	assert(pos < slt->size);
	int cur = pos + 1;
	while (cur < slt->size)
	{
		slt->a[cur - 1] = slt->a[cur];
		cur++;
	}
	slt->size--;
}
int seqlistfind(SLT* slt, SLTdatatype x)
{
	int i = 0;
	while (i < slt->size)
	{
		if (slt->a[i] == x)
		{
			return i;
		}
		i++;
	}
	return -1;
}
void seqlistmodify(SLT* slt, int pos, SLTdatatype x)
{
	assert(pos < slt->size);
	slt->a[pos] = x;
}