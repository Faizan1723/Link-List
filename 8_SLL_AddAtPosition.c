#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

struct node * add_at_end(struct node *ptr, int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    ptr->link=temp;
    return temp;
}
void add_at_position(struct node *ptr,int pos,int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    pos=pos-1;
    while (pos!=1)
    {
        ptr=ptr->link;
        pos=pos-1;
    }

    temp->link=ptr->link;
    ptr->link=temp;
}
int main()
{
    struct node *head=(struct node *)malloc(sizeof(struct node));
    head->data=1;
    head->link=NULL;

    struct node *ptr=head;
    ptr=add_at_end(ptr,2);
    ptr=add_at_end(ptr,3);

    ptr=head;
    int pos=2,data=4;
    add_at_position(ptr,pos,data);
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}
