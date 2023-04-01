#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* circular_singly_list_node(int data)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}
//***********************************************************//
struct node* add_at_front(struct node* tail,int data)
{
    struct node* newptr=malloc(sizeof(struct node));
    newptr->data=data;
    newptr->next=NULL;
    newptr->next=tail->next;
    tail->next=newptr;
    return tail;
}
//**********************************************************//
int main()
{
    struct node* tail;
    struct node* ptr;
    int data;
    tail=circular_singly_list_node(data=1);
    tail=add_at_front(tail,data=2);

    ptr=tail->next;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    } while (ptr!=tail->next);
    return 0;
}