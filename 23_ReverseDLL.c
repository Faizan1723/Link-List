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

struct node * add_at_end(struct node* head,int data)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    struct node* tp=head;
    while (tp->next!=NULL)
    {
        tp=tp->next;
    }
    tp->next=temp;
    temp->prev=tp;
    return head;
}
//************************************************************//
struct node* reverse_list(struct node* head)
{
    struct node* ptr1=head;
    struct node* ptr2=ptr1->next;

    ptr1->next=NULL;
    ptr1->prev=ptr2;

    while(ptr2!=NULL)
    {
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    head=ptr1;
    return head;
}
//***********************************************************//
int main()
{
    struct node* head=NULL;
    struct node* ptr;

    head=add_node(head,1);
    head=add_at_end(head,2);
    head=add_at_end(head,3);
    head=reverse_list(head);
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}
