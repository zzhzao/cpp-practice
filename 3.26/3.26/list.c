#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"
ListNode* ListCreate(int x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
		exit(1);
	newnode->_data = x;
	newnode->_next = newnode;
	newnode->_prev = newnode;
	return newnode;
}
ListNode* ListInit()
{
	ListNode* phead = ListCreate(-1);
	return phead;
}
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newnode = ListCreate(x);
	newnode->_next = pHead;
	newnode->_prev = pHead->_prev;
	pHead->_prev = newnode;
	pHead->_prev->_next = newnode;
}
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newnode = ListCreate(x);
	newnode->_next = pHead->_next;
	newnode->_prev = pHead;
	pHead->_next->_prev = newnode;
	pHead->_next = newnode;
}
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListNode* del = pHead->_prev;
	del->_prev->_next = pHead;
	pHead->_prev = del->_prev;
	free(del);
	del = NULL;
}
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	ListNode* del = pHead->_next;
	pHead->_next = del->_next;
	del->_next->_prev = pHead;
	free(del);
	del = NULL;
}
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* pcur = pHead->_next;
	while (pcur != pHead)
	{
		printf("%d->",pcur->_data);
		pcur = pcur->_next;
	}
}
bool listempty(ListNode* pHead)
{
	if (pHead->_next == pHead)
		return true;
	else
		return false;
}
void ListDestory(ListNode* pHead)
{
	assert(!listempty(pHead));
	ListNode* pcur = pHead->_next;
	while (pcur != pHead)
	{
		ListNode* next = pcur->_next;
		free(pcur);
		pcur = next;
	}
	free(pHead);
	pHead = NULL;
}
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* pcur = pHead->_next;
	while (pcur != pHead)
	{
		if (pcur->_data == x)
			return pcur;
		pcur = pcur->_next;
	}
	return NULL;
}
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = ListCreate(x);
	newnode->_next = pos;
	newnode->_prev = pos->_prev;
	pos->_prev->_next = newnode;
	pos->_prev = newnode;
}
void ListErase(ListNode* pos)
{
	assert(pos);
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
	pos = NULL;
}