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

//�������
SLTNode* BuySTLNode(SLTDataType x);

//����+����ͷ+ѭ��
void SListPrint(SLTNode* plist);
void SListPushBack(SLTNode** pplist, SLTDataType x);
void SListPushFront(SLTNode** pplist, SLTDataType x);

void SListPopBack(SLTNode** pplist);
void SListPopFront(SLTNode** pplist);

//���ҽ��
SLTNode* SListFind(SLTNode* plist, SLTDataType x);

//��posλ�ú����
void SListInsertAfter(SLTNode** pos, SLTDataType x);
//��posλ��ǰ����
void SListInsertPrev(SLTNode** pplist, SLTNode* pos, SLTDataType x);

//��ɾ
void SListEreaseAfter(SLTNode* pos);
//ɾ����ǰλ��
void SListEreaseCur(SLTNode**pplist,SLTNode* pos);
