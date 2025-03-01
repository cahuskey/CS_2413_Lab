#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int x;
    struct Node* next;
} Node;


void insertEnd(Node** head, int value) 
{
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        exit(1);
    }
    newNode->next = NULL;
    newNode->x = value;
    
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    
    Node* curr = *head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    
}

void deallocate(Node** root)
{
    Node* curr = *root;
    whiel(curr != NULL)
    {
        Node* 
    }
}

void printList(Node* head)
{
       for (Node* curr = head; curr != NULL; curr = curr->next)
    {
        printf("%d ", curr->x);
    }
    printf("\n"); 
}


int main()
{
    Node* head = NULL;
    

    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    
    
    printf("Original List: ");
    printList(head);
    
    


    return 0;
}
