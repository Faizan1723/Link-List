#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* add_at_end(struct node *ptr,int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    ptr->link=temp;
    return temp;
}

//*******************************************************//
struct node* sort_insert(struct node* head,int data)
{
    struct node* newp=malloc(sizeof(struct node));
    newp->data=data;
    newp->link=NULL;
    int key=newp->data;

    if(head==NULL||key<head->data)
    {
        newp->link=head;
        head=newp;
    }
    else
    {
        struct node* temp=head;
        while(temp->link!=NULL && temp->link->data<key)
        {
            temp=temp->link;
        }
        newp->link=temp->link;
        temp->link=newp;
    }
    return head;
}
//*******************************************************//

int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=1;
    head->link=NULL;

    struct node *ptr=head;
    ptr=add_at_end(ptr,2);
    ptr=add_at_end(ptr,3);
    ptr=add_at_end(ptr,4);

    head=sort_insert(head,0);
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}