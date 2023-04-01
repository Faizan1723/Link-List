//THIS METHOD OF ADDING A NODE AT THE END IS NOT EFFICIENT IN TERMS OF TIME //
//A MORE OPTIMAL CODE IS WRITTEN IN THE FILE 6(2)_AddAtEndOfList.c//

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void add_at_last(struct node *head, int data)
{
    struct node *ptr,*temp;
    ptr=head;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    while (ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;

}

int main()
{
    struct node *head;
    head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=1;
    head->link=NULL;

    struct node *current=NULL;
    current=(struct node*)malloc(sizeof(struct node));
    current->data=2;
    current->link=NULL;
    head->link=current;

    current=malloc(sizeof(struct node));
    current->data=3;
    current->link=NULL;
    head->link->link=current;

    add_at_last(head,4);

    return 0;
}