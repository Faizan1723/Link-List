#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node* circular_doubly_list_node(int data)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    temp->prev=temp;
    return temp;
}
struct node* add_at_end(struct node* tail,int data)
{
    struct node* ptr=malloc(sizeof(struct node));
    ptr->prev=NULL;
    ptr->data=data;
    ptr->next=NULL;

    struct node* newptr=tail->next;
    ptr->prev=tail;
    ptr->next=newptr;
    newptr->prev=ptr;
    tail->next=ptr;
    tail=ptr;
    return tail;
}

//*****************************************************//
struct node* del_at_pos(struct node* tail,int pos)
{
    struct node* temp=tail->next;
    while (pos>1)
    {
        temp=temp->next;
        pos--;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    if(temp==tail)
    {
        tail=tail->prev;
    }
    free(temp);
    temp=NULL;
    return tail;
}
//*****************************************************//

int main()
{
    struct node* tail;
    tail=circular_doubly_list_node(1);
    tail=add_at_end(tail,2);
    tail=add_at_end(tail,3);
    tail=add_at_end(tail,4);
    int pos=3;
    tail=del_at_pos(tail,pos);

    struct node* ptr=tail->next;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    while (ptr!=tail->next);
        
    return 0;
}