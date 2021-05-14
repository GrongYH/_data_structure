#include"Heap.h"

void HeapInit(Heap* php, HPDataType* a, int n)
{
	assert(php);
	php->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (php->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	else
	{
		memcpy(php->a, a, sizeof(HPDataType) * n);
		CreatHeap(php->a, n);
		php->capacity = php->size = n;
	}
}
void HeapDestory(Heap* php)
{
	assert(php);
	php->capacity = php->size = 0;
	free(php->a);
	php->a = NULL;
}
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		HPDataType* tmp = (HPDataType*)realloc(php->a, php->capacity * sizeof(HPDataType) * 2);
		if (!tmp)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			php->a = tmp;
			php->capacity *= 2;
		}
	}
	php->a[php->size++] = x;
	AdjustUp(php->a, php->size, php->size - 1);
}
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[0], &php->a[--php->size]);
	
	AdjustDown(php->a, php->size, 0);
}
void AdjustUp(HPDataType* arr, int length, int child)
{
	int parent = (child - 1) >> 1;
	while (child > 0)
	{
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
		{
			break;
		}
	}
}

void Swap(HPDataType* a, HPDataType* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void AdjustDown(HPDataType* arr, int length, int parent)
{
	int child = 2 * parent + 1;
	while (child < length)
	{
		if (child + 1 < length && arr[child + 1] > arr[child])
		{
			++child;
		}
		if (arr[child] > arr[parent])
		{
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void CreatHeap(HPDataType* arr, int length)
{
	for (int i = (length-1-1)>>1; i >= 0; i--)
	{
		AdjustDown(arr, length, i);
	}
}
void HeapSort(HPDataType* arr, int length)
{
	CreatHeap(arr, length);
	int end = length - 1;
	while (end > 0)
	{
		Swap(&arr[end], &arr[0]);
		AdjustDown(arr, end, 0);
		end--;
	}
}

void HeapPrint(Heap* php)
{
	assert(php);
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
	int count = 0;
	int rcount = 1;
	while (count < php->size)
	{
		int i = 0;
		while (i < rcount)
		{
			if (count >= php->size)
			{
				break;
			}
			printf("%d ", php->a[count]);
			i++;
			count++;
		}
		printf("\n");
		rcount <<= 1;
	}
}