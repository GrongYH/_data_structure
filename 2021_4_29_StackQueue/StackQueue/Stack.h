#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>


typedef int STDataType;
typedef struct Stack Stack;

struct Stack
{
	STDataType* a;
	int top;         //栈顶
	int capacity;   //容量，方便增容
};

void StackInit(Stack* pst);
void StackDestory(Stack* pst);
//入栈出栈
void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);
STDataType StackTop(Stack* pst);

bool StackisEmpty(Stack* pst);
int StackSize(Stack* pst);



