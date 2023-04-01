#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* add_at_front(struct node *head,int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    temp->link=head;
    head=temp;

    return head;
} 
int main()
{
    struct node *head=(struct node *)malloc(sizeof(struct node));
    head->data=1;
    head->link=NULL;

    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=2;
    ptr->link=NULL;

    head->link=ptr;

    int data=3;
    head=add_at_front(head,data);

    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}