#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* prev;
    int data;
    struct node* next; 
};
struct node* add_node(struct node *head,int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    
    head=temp;
    return head;
}
//**********************************************************//
struct node* add_at_front(struct node* head,int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}
//**********************************************************//
int main()
{
    struct node* head=NULL;
    struct node *ptr;
    head=add_node(head,1);
    head=add_at_front(head,2);

    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    
}