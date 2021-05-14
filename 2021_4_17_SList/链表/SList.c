#include "SList.h" 

void SListPrint(SLTNode* plist)
{
	SLTNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLTNode* BuySTLNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	if (node!=NULL)
	{
		node->data = x;
		node->next = NULL;
	}
	return node;
}


void SListPushBack(SLTNode** pplist, SLTDataType x)
{
	SLTNode* newnode = BuySTLNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPushFront(SLTNode** pplist, SLTDataType x)
{
	SLTNode* newnode = BuySTLNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

void SListPopBack(SLTNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
		tail = NULL;
	}
}

void SListPopFront(SLTNode** pplist)
{
	if ((*pplist) == NULL)
	{
		return;
	}
	else
	{
		SLTNode* next = *pplist;
		next = (*pplist)->next;
		free(*pplist);
		*pplist = next;
	}
}


SLTNode* SListFind(SLTNode* plist, SLTDataType x)
{
	SLTNode* cur = plist;
	while (cur)
	{
		if ((*cur).data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsertAfter(SLTNode** pos, SLTDataType x)
{
	SLTNode* newnode = BuySTLNode(x);
	if (*pos == NULL)
	{
		*pos = newnode;
	}
	else
	{
		newnode->next = (*pos)->next;
		(*pos)->next = newnode;
	}
}

void SListInsertPrev(SLTNode** pplist, SLTNode* pos, SLTDataType x)
{
	SLTNode* newnode = BuySTLNode(x);
	if (pos == *pplist)
	{
		newnode->next = pos;
		*pplist = newnode;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* cur = *pplist;
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		if (prev)
		{
			prev->next = newnode;
		}
		newnode->next = pos;
	}
}

void SListEreaseAfter(SLTNode* pos)
{
	if (pos == NULL||pos->next ==NULL)
	{
		return;
	}
	else
	{
		SLTNode* next = pos->next;
		pos->next = next->next;
		free(next);
		next = NULL;
	}
}

void SListEreaseCur(SLTNode** pplist, SLTNode* pos)
{
	if (pos == NULL || *pplist == NULL )
	{
		return;
	}
	else if(pos == *pplist)
	{
		*pplist = (*pplist)->next;
		free(pos);
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* cur = *pplist;
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		free(cur);
	}
}