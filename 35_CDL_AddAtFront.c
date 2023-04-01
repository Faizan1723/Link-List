#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* circular_doubly_list_node(int data)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;

    temp->prev=temp;
    temp->next=temp;
    return temp;
}

//******************************************************//
struct node* add_at_front(struct node* tail,int data)
{
    struct node* ptr=circular_doubly_list_node(data);
    if(tail==NULL)
        return ptr;
    else
    {
        struct node* newptr=tail->next;
        ptr->next=newptr;
        ptr->prev=tail;
        newptr->prev=ptr;
        tail->next=ptr;
    }
    return tail;
}
//******************************************************//
int main()
{
    struct node* tail=(struct node*)malloc(sizeof(struct node));
    tail=circular_doubly_list_node(1);
    tail=add_at_front(tail,2);
    tail=add_at_front(tail,3);

    struct node* ptr;
    ptr=tail->next;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    } while (ptr!=tail->next);

    return 0;
}