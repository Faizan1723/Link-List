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
struct node* del_at_pos(struct node* head,int pos)
{
    struct node* temp=head;
    struct node* temp2;
    while(pos>1)
    {
        temp=temp->next;
        pos--;
    }
    temp2=temp->prev;
    temp2->next=temp->next;
    temp->next->prev==temp2;
    free(temp);
    temp=NULL;
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
    int pos=2;
    head=del_at_pos(head,pos);
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}
