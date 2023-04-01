#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* prev;
    int data;
    struct node* next; 
};
//*********************************************************************//
struct node* add_node(struct node *head,int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    
    head=temp;
    return head;
}
//********************************************************************//
int main()
{
    struct node* head=NULL;
    head=add_node(head,1);
    printf("%d",head->data);
    return 0;
}
