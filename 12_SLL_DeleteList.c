#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node * del_list(struct node *head)
{
    struct node *temp=head;
    while (temp!=NULL)
    {
        temp=temp->link;
        free(head);
        head=temp;
    }
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

    head=del_list(head);
    if(head==NULL)
        printf("THE LIST HAS BEEN DELETED");
    return 0;
}