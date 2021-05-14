#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;

void HeapInit(Heap* php, HPDataType* a, int n);
void HeapDestory(Heap* php);
void HeapPush(Heap* php, HPDataType x);
void HeapPop(Heap* php);
void AdjustUp(HPDataType* arr, int length, int child);

void Swap(HPDataType* a, HPDataType* b);
void AdjustDown(HPDataType* arr, int length,int parent);
void CreatHeap(HPDataType* arr, int length);
void HeapSort(HPDataType* arr, int length);

void HeapPrint(Heap* php);
