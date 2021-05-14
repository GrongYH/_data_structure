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

//尾插
void ListPushBack(ListNode* phead, LTDataType x);

//头插
void ListPushFront(ListNode* phead, LTDataType x);

//尾删
void ListPopBack(ListNode* phead);

//头删
void ListPopFront(ListNode* phead);

//查找
ListNode* ListFind(ListNode* phead, LTDataType x);

//插入
void ListInsert(ListNode* pos, LTDataType x);

//删除
void ListErease(ListNode* pos);

int isVoid(ListNode* phead);

int ListSize(ListNode* phead);

void ListDestory(ListNode* phead);//注意phead也要释放


