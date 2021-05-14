
#include "List.h"

void TestList()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPopFront(plist);
	ListPrint(plist);
	printf("%d\n",ListSize(plist));
	ListDestory(plist);
}



int main()
{
	TestList();
	return 0;
}