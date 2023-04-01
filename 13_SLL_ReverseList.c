#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node * rev_list(struct node *head)
{
    struct node *back=NULL;
    struct node *front=NULL;

    while (head!=NULL)
    {
        front=head->link;
        head->link=back;
        back=head;
        head=front;
    }
    head=back;
    return head;
}
int main()
{
    struct node *head=(struct node *)malloc(sizeof(struct node));
    head->data=1;
    head->link=NULL;
    
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=2;
    ptr->link=NULL;
    head->link=ptr;

    ptr=malloc(sizeof(struct node));
    ptr->data=3;
    ptr->link=NULL;
    head->link->link=ptr;

    head=rev_list(head);
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}