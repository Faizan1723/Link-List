#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* circular_singly_list_node(int data)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}

struct node* add_at_last(struct node* tail,int data)
{
    struct node* newptr=(struct node*)malloc(sizeof(struct node));
    newptr->data=data;
    newptr->next=NULL;

    newptr->next=tail->next;
    tail->next=newptr;
    tail=tail->next;
    return tail;
}

//*********************************************************//
int search_node(struct node* tail,int data)
{
    int index=0;
    struct node* ptr;
    if(tail==NULL)
        return -2;
    ptr=tail->next;
    do
    {
        if(ptr->data==data)
            return index;
        ptr=ptr->next;
        index++;
    } while (ptr!=tail->next);
    return -1;
}
//*********************************************************//

int main()
{
    struct node* tail=NULL;
    int data;
    tail=circular_singly_list_node(1);
    tail=add_at_last(tail,2);
    tail=add_at_last(tail,3);
    tail=add_at_last(tail,4);
    tail=add_at_last(tail,5);
 
    printf("ENTER THE DATA TO BE SEARCHED IN THE LIST: ");
    scanf("%d",&data);
    int index;
    index=search_node(tail,data);
    if(index==-1)
        printf("\nTHE SEARCHED DATA IS NOT FOUND IN THE LIST\n");
    else if(index==-2)
        printf("\nTHE LINK LIST IS EMPTY\n");
    else
        printf("\nTHE SEARCHED DATA IS PRESENT IN NODE %d OF THE LINK LIST",index);
    return 0;
}