#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

typedef int LTDataType;
typedef struct ListNode ListNode;

struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	LTDataType data;
};

ListNode* BuyListNode(LTDataType x);

ListNode* ListInit();

void ListPrint(ListNode* phead);

//β��
void ListPushBack(ListNode* phead, LTDataType x);

//ͷ��
void ListPushFront(ListNode* phead, LTDataType x);

//βɾ
void ListPopBack(ListNode* phead);

//ͷɾ
void ListPopFront(ListNode* phead);

//����
ListNode* ListFind(ListNode* phead, LTDataType x);

//����
void ListInsert(ListNode* pos, LTDataType x);

//ɾ��
void ListErease(ListNode* pos);

int isVoid(ListNode* phead);

int ListSize(ListNode* phead);

void ListDestory(ListNode* phead);//ע��pheadҲҪ�ͷ�


