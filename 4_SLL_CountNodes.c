#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void count_node(struct node * head )
{
    int count=0;
    /*if(head==NULL);
        printf("Linked List Is Empty");*/

    struct node *ptr=NULL;
    ptr=head;
    while (ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    printf("TOTAL NO. OF NODES IN THE LINKED LIST IS: %d",count);
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

    count_node(head);

    //printf("%d",*(head->link->link));
    
    return 0;
}