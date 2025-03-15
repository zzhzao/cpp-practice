#pragma once


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//数据类型为PersonInfo 



//typedef int SQDataType;
//动态顺序表 



#define NAME_MAX 100
#define SEX_MAX 4
#define TEL_MAX 11
#define ADDR_MAX 100

typedef struct SeqList contact;
typedef struct PersonInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

typedef struct SeqList {
	PeoInfo* a;
	int size;//保存有效数据个数 
	int capacity;//空间的⼤⼩ 
}SLT;
typedef struct PersonInfo SQDataType;
//初始化通讯录 

void InitContact(contact* con);

//添加通讯录数据 

void AddContact(contact* con);

//删除通讯录数据 

void DelContact(contact* con);

//展⽰通讯录数据 

void ShowContact(contact* con);

//查找通讯录数据 

void FindContact(contact* con);

//修改通讯录数据 

void ModifyContact(contact* con);

//销毁通讯录数据 

void DestroyContact(contact* con);

