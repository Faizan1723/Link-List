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

struct node* add_at_front(struct node* tail,int data)
{
    struct node* newptr=malloc(sizeof(struct node));
    newptr->data=data;
    newptr->next=NULL;

    newptr->next=tail->next;
    tail->next=newptr;
    return tail;
}

struct node* add_at_last(struct node* tail,int data)
{
    struct node* newptr=malloc(sizeof(struct node));
    newptr->data=data;
    newptr->next=NULL;

    newptr->next=tail->next;
    tail->next=newptr;
    tail=tail->next;
    return tail;
}

//**********************************************************//
struct node* add_at_pos(struct node* tail,int data,int pos)
{
    struct node* newp=(struct node*)malloc(sizeof(struct node));
    newp->data=data;
    newp->next=NULL;

    struct node* p=tail->next;
    while (pos>1)
    {
        p=p->next;
        pos--;
    }
    newp->next=p->next;
    p->next=newp;
    if(p==tail)
    {
        tail=tail->next;
    }
    return tail;
}
//**********************************************************//

int main()
{
    struct node* tail;
    struct node* ptr;
    int data;
    tail=circular_singly_list_node(data=1);
    tail=add_at_front(tail,data=3);
    tail=add_at_last(tail,data=2);
    int pos=2;
    tail=add_at_pos(tail,data=4,pos);

    ptr=tail->next;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    } while (ptr!=tail->next);
    
    return 0;
}