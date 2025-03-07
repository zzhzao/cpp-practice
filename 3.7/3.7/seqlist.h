#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTdatatype;

typedef struct seqlist
{
	SLTdatatype* a;
	int size;
	int capacity;
}SLT;
void seqlistInit(SLT* slt);
void seqlistInit(SLT* slt);
void seqlistCheckCapacity(SLT* slt);
void seqlistprint(SLT* slt);

void seqlistpushback(SLT* slt, SLTdatatype x);

void seqlistpushfront(SLT* slt, SLTdatatype x);


void seqlistpopback(SLT* slt);
void seqlistpopfront(SLT* slt);
void seqlistInsert(SLT* slt, int pos, SLTdatatype x);
void seqlistpop(SLT* slt, int pos);
int seqlistfind(SLT* slt, SLTdatatype x);
void seqlistmodify(SLT* slt, int pos, SLTdatatype x);