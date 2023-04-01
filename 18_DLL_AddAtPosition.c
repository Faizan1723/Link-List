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
void add_at_end(struct node* head,int data)
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
}
//*********************************************************//
struct node* add_at_pos(struct node *head,int data,int pos)
{
    struct node* newptr=NULL;
    struct node* temp1=head;
    struct node* temp2=NULL;

    newptr=add_node(newptr,data);
    while (pos!=2)
    {
        temp1=temp1->next;
        pos--;
    }
    if(temp1->next==NULL)
    {
        temp1->next=newptr;
        newptr->prev=temp1;
    }
    if (pos==1)
    {
        head=add_at_front(head,data);
    }
    else
    {
        temp2=temp1->next;

        temp1->next=newptr;
        temp2->prev=newptr;
        newptr->next=temp2;
        newptr->prev=temp1;
    }
    return head;
}
//********************************************************//
int main()
{
    struct node* head=NULL;
    struct node *ptr;
    head=add_node(head,2);
    head=add_at_front(head,1);
    add_at_end(head,3);
    int pos=1;
    head=add_at_pos(head,4,pos);

    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}
