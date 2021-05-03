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
struct Node* createNewNode(int ele)
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
        struct Node* newNode = createNewNode(ele);
        SLL->head = SLL->last = newNode;
    }
    else
    {
       struct Node* newNode = createNewNode(ele);
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
}
int main()
{
    struct SinglyLinkedList* SLL = createSinglyLinkedList();
    insertNode(SLL,10);
    insertNode(SLL,40);
    insertNode(SLL,20);
    insertNode(SLL,30);
    insertNode(SLL,15);
    printSLL(SLL);
}