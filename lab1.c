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

struct Node* removeElements(struct Node* head, int value) {
    
    Node* temp = malloc(sizeof(Node));
    temp->next = head;
    Node* curr = temp;

    
    while (curr->next != NULL) {
        if (curr->next->x == value) {
            Node* dummy = curr->next;
            curr->next = curr->next->next; 
            free(dummy); 
        } else {
            curr = curr->next; 
        }
    }

    
    Node* newHead = temp->next;
    free(temp); 
    return newHead;
}

struct ListNode* reverseList(struct Node* head)
{
    
}


void deallocate(Node** head)
{
    Node* curr = *head;
    while(curr != NULL)
    {
        Node* block = curr;
        curr = curr->next;
        free(block);
    }
    *head = NULL;
}

void printList(Node* head)
{
       for (Node* curr = head; curr != NULL; curr = curr->next)
    {
        printf("%d ", curr->x);
    }
    printf("\n\n"); 
}


int main()
{
    Node* head = NULL;
    

    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 6);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    insertEnd(&head, 6);
    
    
    printf("Original List: ");
    printList(head);
    
    head = removeElements(head, 6);
    
    printf("New List: ");
    printList(head);
    
    deallocate(&head);


    return 0;
}
