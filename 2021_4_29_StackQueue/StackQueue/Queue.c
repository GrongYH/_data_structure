#include"Queue.h"
void QueueInit(Queue* pq)
{
	pq->head = pq->tail = NULL;
}

void QueueDestory(Queue* pq)
{
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode==NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}
	if (pq->tail==NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}
QDataType QueueBank(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->tail->data;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head==NULL;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	int Size = 0;
	while (cur)
	{
		++Size;
		cur = cur->next;
	}
	return Size;
}