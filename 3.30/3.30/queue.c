#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
}
void QueuePush(Queue* q, QDataType data)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		exit(1);
	}
	newnode->_data = data;
	newnode->_next = NULL;
	if (q->_front == q->_rear)
	{
		q->_front = q->_rear = newnode;
	}
	else
	{
		q->_rear->_next = newnode;
		q->_rear = newnode;
	}
}
bool QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL;
}
void QueuePop(Queue* q)
{
	assert(!QueueEmpty(q));
	if (q->_front == q->_rear)
	{
		free(q->_front);
		q->_front = NULL;
	}
	else
	{
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
	}

}
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_data;
}
int QueueSize(Queue* q)
{
	int count = 0;
	QNode* pcur = q->_front;
	while (pcur)
	{
		count++;
		pcur = pcur->_next;
	}
	return count;
}
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* pcur = q->_front;
	while (pcur)
	{
		QNode* next = pcur->_next;
		free(pcur);
		pcur = next;
	}
	q->_front = q->_rear = NULL;
}