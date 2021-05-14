#include"Heap.h"

void test()
{
	int arr[] = { 2,5,1,6,5,2,7,8,9,0 };
	int length = sizeof(arr) / sizeof(arr[0]);
	Heap hp;
	HeapInit(&hp, arr, length);
	HeapPrint(&hp);
	HeapPush(&hp, 10);
	HeapPrint(&hp);
	HeapPush(&hp, -1);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapDestory(&hp);
}

int main()
{
	test();
	return 0;
}