#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void print_node(struct node * head)
{
    if(head==NULL)
        printf("THE LINK LIST IS EMPTY\n");
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {   
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}
int main()
{
    struct node *head=NULL;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=1;
    head->link=NULL;
    
    struct node *current=malloc(sizeof(struct node));
    current->data=2;
    current->link=NULL;
    head->link=current;

    current=malloc(sizeof(struct node));
    current->data=3;
    current->link=NULL;
    head->link->link=current;

    print_node(head);

    //printf("%d",*(head->link->link));
    
    return 0;
}