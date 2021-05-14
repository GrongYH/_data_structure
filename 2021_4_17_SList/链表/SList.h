#pragma once

#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	int data;
	struct SListNode* next;
}SLTNode;

//创建结点
SLTNode* BuySTLNode(SLTDataType x);

//单向+不带头+循环
void SListPrint(SLTNode* plist);
void SListPushBack(SLTNode** pplist, SLTDataType x);
void SListPushFront(SLTNode** pplist, SLTDataType x);

void SListPopBack(SLTNode** pplist);
void SListPopFront(SLTNode** pplist);

//查找结点
SLTNode* SListFind(SLTNode* plist, SLTDataType x);

//在pos位置后插入
void SListInsertAfter(SLTNode** pos, SLTDataType x);
//在pos位置前插入
void SListInsertPrev(SLTNode** pplist, SLTNode* pos, SLTDataType x);

//后删
void SListEreaseAfter(SLTNode* pos);
//删除当前位置
void SListEreaseCur(SLTNode**pplist,SLTNode* pos);
