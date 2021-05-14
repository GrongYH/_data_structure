#include"Stack.h"
#include"Queue.h"
typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* s1 = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&s1->q1);
    QueueInit(&s1->q2);
    return s1;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1, x);
    }
    else
    {
        QueuePush(&obj->q2, x);
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj)
{
    if (!QueueEmpty(&obj->q1))
    {
        while(QueueSize(&obj->q1)>1)
        {
            QDataType x = QueueFront(&obj->q1);
            QueuePop(&obj->q1);
            QueuePush(&obj->q2, x);
        }
        QDataType x = QueueFront(&obj->q1);
        QueuePop(&obj->q1);
        return x;
    }
    else
    {
        while (QueueSize(&obj->q2) > 1)
        {
            QDataType x = QueueFront(&obj->q2);
            QueuePop(&obj->q2);
            QueuePush(&obj->q1, x);
        }
        QDataType x = QueueFront(&obj->q2);
        QueuePop(&obj->q2);
        return x;
    }

}
//int myStackPop(MyStack* obj)
//{
//    Queue* pNonEmpty = &obj->q1;
//    Queue* pEmpty = &obj->q2;
//    if (QueueEmpty(&obj->q1))
//    {
//        pNonEmpty = &obj->q2;
//        pEmpty = &obj->q1;
//    }
//    while (QueueSize(pNonEmpty) > 1)
//    {
//        QueuePush(pEmpty, QueueFront(pNonEmpty));
//        QueuePop(pNonEmpty);
//    }
//    int x = QueueFront(pNonEmpty);
//    QueuePop(pNonEmpty);
//    return x;
//}

/** Get the top element. */
int myStackTop(MyStack* obj)
{
    if (!QueueEmpty(&obj->q1))
        return QueueBank(&obj->q1);
    else
        return QueueBank(&obj->q2);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj)
{
    if (QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2))
        return true;
    else
        return false;
}

//void myStackFree(MyStack* obj)
//{
//    free(obj);
//}

void TestQueue()
{
    MyStack* st = myStackCreate();
    myStackPush(st, 1);
    myStackPush(st, 2);
    myStackPush(st, 3);
    myStackPush(st, 4);
    myStackPop(st);
    myStackPop(st);
}
int main()
{

    TestQueue();
	return 0;
}