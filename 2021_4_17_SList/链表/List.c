#include"List.h"

ListNode* BuyListNode(LTDataType x) 
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node)
	{
		node->data = x;
		node->next = NULL;
		node->prev = NULL;
	}
	return node;
}


ListNode* ListInit()
{
	ListNode* phead = BuyListNode(-1);
	assert(phead);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* prev = pos->prev;
	prev->next = newnode;
	newnode->next = pos;
	pos->prev = newnode;
	newnode->prev = prev;
}

void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListInsert(phead, x);
}

void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListInsert(phead->next->next, x);
}

void ListErease(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}

void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->prev != phead);
	ListErease(phead->prev);
}

void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListErease(phead->next);
}

ListNode* ListFind(ListNode* phead, LTDataType x)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	printf("Head<->");
	while (cur != phead)
	{
		printf("%d<->", cur->data);
		cur = cur->next;
	}
	printf("Head\n");
}

int isVoid(ListNode* phead)
{
	assert(phead);
	if (phead->next == phead)
	{
		return 1;
	}
	return 0;
}


int ListSize(ListNode* phead)
{
	assert(phead);
	int Size = 0;
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		Size++;
		cur = cur->next;
	}
	return Size;
}

void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}

