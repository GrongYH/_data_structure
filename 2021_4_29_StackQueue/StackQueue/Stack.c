#include"Stack.h"

void StackInit(Stack* pst)
{
	assert(pst);
	pst->a = (STDataType*)malloc(sizeof(STDataType)*4);
	pst->capacity = 4;
	pst->top = 0;
}

void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}

void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * pst->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		pst->a = tmp;
		pst->capacity *= 2;
	}
	pst->a[pst->top++] = x;
}

void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackisEmpty(pst));
	pst->top--;
}

STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(!StackisEmpty(pst));

	return pst->a[pst->top - 1];
}

bool StackisEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0;
}

int StackSize(Stack* pst)
{
	assert(pst);
	return pst->top;
}