#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void del_at_pos(struct node **head,int pos)
{
    struct node *ptr1=*head;
    struct node *ptr2=*head;
    if(pos==1)
    {
        *head=ptr1->link;
        free(ptr1);
        ptr1=NULL;
    }
    else
    {
        while (pos!=1)
        {
            ptr1=ptr2;
            ptr2=ptr2->link;
            pos--;
        }
        ptr1->link=ptr2->link;
        free(ptr2);
        ptr2=NULL;
    }
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

    int pos=2;
    del_at_pos(&head,pos);
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}