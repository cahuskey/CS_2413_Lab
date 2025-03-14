#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
    int* stack1;
    int* stack2;
    int top1;
    int top2;
    int size1;
    int size2;
} MyQueue;

MyQueue* myQueueCreate()
{
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->stack1 = (int*)malloc(100 * sizeof(int));
    obj->stack2 = (int*)malloc(100 * sizeof(int));
    obj->top1 = -1;
    obj->top2 = -1;
    obj->size1 = 100;
    obj->size2 = 100;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) 
{
    obj->stack1[++(obj->top1)] = x;
}

int myQueuePop(MyQueue* obj) 
{
    if (obj->top2 == -1) 
    {
        while (obj->top1 != -1) 
        {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        }
    }
    return obj->stack2[(obj->top2)--];
}

int myQueuePeek(MyQueue* obj) 
{
    if (obj->top2 == -1) 
    {
        while (obj->top1 != -1) 
        {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        }
    }
    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) 
{
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) 
{
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}

int main() 
{
    MyQueue* queue = myQueueCreate();

    myQueuePush(queue, 1);
    myQueuePush(queue, 2);
    myQueuePush(queue, 3);
    myQueuePush(queue, 4);
    
    printf("Peak next out: %d\n", myQueuePeek(queue));

    printf("Pop element: %d\n", myQueuePop(queue));
    printf("Pop element: %d\n", myQueuePop(queue));
    
    printf("Peek next out: %d\n", myQueuePeek(queue));




    printf("Is queue empty? %s\n", myQueueEmpty(queue) ? "Yes" : "No");




    myQueueFree(queue);

    return 0;
}

