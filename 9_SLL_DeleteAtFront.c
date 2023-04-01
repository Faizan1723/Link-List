#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* del_at_front(struct node *head)
{
    if(head==NULL)
        printf("THE LINK LIST IS EMPTY\n");
    else
    {
        struct node*temp=head;
        head=head->link;
        free(temp);
        temp=NULL;
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

    head=del_at_front(head);
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}