#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link1;
    struct node* link2;
};

int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=1;
    head->link1=NULL;
    head->link2=NULL;

    struct node *ptr1=(struct node*)malloc(sizeof(struct node));
    ptr1->data=2;
    ptr1->link1=NULL;
    ptr1->link2=NULL;

    head->link1=ptr1;
    ptr1->link2=head;

    ptr1=malloc(sizeof(struct node));
    ptr1->data=3;
    ptr1->link1=NULL;
    ptr1->link2=NULL;

    head->link1->link1=ptr1;
    ptr1->link2=head->link1;
    
    while (ptr1!=NULL)
    {
        printf("%d ",ptr1->data);
        ptr1=ptr1->link2;
    }
    return 0;
}