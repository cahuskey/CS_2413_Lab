#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *arr;      
    int front;     
    int rear;      
    int size;     
    int capacity;  
} MyQueue;


MyQueue* myQueueCreate() 
{
    MyQueue *obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->capacity = 1000; 
    obj->arr = (int*)malloc(obj->capacity * sizeof(int));
    obj->front = 0;
    obj->rear = 0;
    obj->size = 0;
    return obj;
}


void myQueuePush(MyQueue* obj, int x) 
{
    if (obj->size < obj->capacity) 
    {
        obj->arr[obj->rear] = x;
        obj->rear = (obj->rear + 1) % obj->capacity;
        obj->size++;
    }
}


int myQueuePop(MyQueue* obj)
{
    if (obj->size > 0) 
    {
        int val = obj->arr[obj->front];
        obj->front = (obj->front + 1) % obj->capacity;
        obj->size--;
        return val;
    }
    return -1; 
}


int myQueuePeek(MyQueue* obj) 
{
    if (obj->size > 0) 
    {
        return obj->arr[obj->front];
    }
    return -1;
}


bool myQueueEmpty(MyQueue* obj) 
{
    return obj->size == 0;
}


void myQueueFree(MyQueue* obj) 
{
    free(obj->arr);
    free(obj);
}


typedef struct 
{
    MyQueue* queue1;  
    MyQueue* queue2;  
} MyStack;


MyStack* myStackCreate() 
{
    MyStack *obj = (MyStack*)malloc(sizeof(MyStack));
    obj->queue1 = myQueueCreate();
    obj->queue2 = myQueueCreate();
    return obj;
}


void myStackPush(MyStack* obj, int x) 
{
    
    myQueuePush(obj->queue1, x);
}


int myStackPop(MyStack* obj) 
{
    if (myQueueEmpty(obj->queue1))
    {
        return -1;  
    }

    
    while (obj->queue1->size > 1) 
    {
        int val = myQueuePop(obj->queue1);
        myQueuePush(obj->queue2, val);
    }

    
    int poppedVal = myQueuePop(obj->queue1);

    
    MyQueue* temp = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = temp;

    return poppedVal;
}


int myStackTop(MyStack* obj) 
{
    if (myQueueEmpty(obj->queue1)) 
    {
        return -1; 
    }

    while (obj->queue1->size > 1) 
    {
        int val = myQueuePop(obj->queue1);
        myQueuePush(obj->queue2, val);
    }

    
    int topVal = myQueuePeek(obj->queue1);

    
    myQueuePush(obj->queue2, myQueuePop(obj->queue1));

    
    MyQueue* temp = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = temp;

    return topVal;
}


bool myStackEmpty(MyStack* obj) 
{
    return myQueueEmpty(obj->queue1);
}

void myStackFree(MyStack* obj) 
{
    myQueueFree(obj->queue1);
    myQueueFree(obj->queue2);
    free(obj);
}



int main() 
{
    MyStack* obj = myStackCreate();

    myStackPush(obj, 1);
    myStackPush(obj, 2);
    myStackPush(obj, 3);

    printf("View top: %d\n", myStackTop(obj));  

    printf("Pop element: %d\n", myStackPop(obj));    

    printf("View top: %d\n", myStackTop(obj));  

    printf("Is the stack empty? %s\n", myStackEmpty(obj) ? "Yes" : "No");  // Expected output: No

    myStackFree(obj);

    return 0;
}
