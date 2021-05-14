#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>


typedef int STDataType;
typedef struct Stack Stack;

struct Stack
{
	STDataType* a;
	int top;         //ջ��
	int capacity;   //��������������
};

void StackInit(Stack* pst);
void StackDestory(Stack* pst);
//��ջ��ջ
void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);
STDataType StackTop(Stack* pst);

bool StackisEmpty(Stack* pst);
int StackSize(Stack* pst);



