#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct SinglyLinkedList
{
    struct Node* head;
    struct Node* last;
};
struct SinglyLinkedList* createSinglyLinkedList()
{
    struct SinglyLinkedList* SLL = (struct SinglyLinkedList*)malloc(sizeof(struct SinglyLinkedList));
    SLL->head = SLL->last = NULL;
    return SLL;
}
struct Node* createNode(int ele)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ele;
    newNode->next = NULL;
    return newNode;
}
void insertNode(struct SinglyLinkedList* SLL, int ele)
{
    if(SLL->last==NULL)
    {
        struct Node* newNode = createNode(ele);
        SLL->head = SLL->last = newNode;
    }
    else
    {
        struct Node* newNode = createNode(ele);
        SLL->last->next = newNode;
        SLL->last = newNode;
    }
}
void printSLL(struct SinglyLinkedList* SLL)
{
    struct Node* temp = SLL->head;
    while(temp!=NULL)
    {
         printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
   
}
void deleteNode(struct SinglyLinkedList* SLL,int ele)
{
    struct Node* temp = SLL->head;
    struct Node* prev = NULL;
    while(temp!=NULL && temp->data != ele)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp!=NULL)
    {
        if(temp==SLL->head)
        {
            SLL->head = temp->next;
            free(temp);
        }
        else if(temp->next==NULL)
        {
            prev->next = NULL;
            free(temp);
            SLL->last = prev;
        }
        else
        {
            prev->next = temp->next;
            free(temp);
        }
    }

}
int main()
{
    struct SinglyLinkedList* SLL = createSinglyLinkedList();
    insertNode(SLL,10);
    insertNode(SLL,40);
    insertNode(SLL,30);
    insertNode(SLL,20);
    insertNode(SLL,50);
    printSLL(SLL);
    deleteNode(SLL,10);
    printSLL(SLL);

}