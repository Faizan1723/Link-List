#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
//NOTE: THIS FUNCTION WILL WORK ONLY IF THE NODE TO BE DELETED IS NOT THE LAST NODE OR FIRST NODE// 
void del_at_pos(struct node* head,int pos)
{
    struct node *q=head;
    int i=1;
    while(i<pos)
    {
        q=q->link;
        i++;
    }
    // int i=pos-1;
    // while(i!=1)
    // {
    //     q=q->link;
    //     pos--;
    // }
    struct node *temp=q->link;
    q->data=temp->data;
    q->link=temp->link;
    free(temp);
    temp=NULL;
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

    ptr=malloc(sizeof(struct node));
    ptr->data=4;
    ptr->link=NULL;
    head->link->link->link=ptr;
    
    int pos=2;
    del_at_pos(head,pos);
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}