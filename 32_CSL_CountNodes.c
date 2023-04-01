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
struct node* create_list(struct node* tail)
{
    int n,data;
    printf("ENTER THE NO. OF NODES OF THE LINK LIST: ");
    scanf("%d",&n);
    if (n==0)
        return tail;
    printf("ENTER THE ELEMENT 1 OF THE LIST: ");
    scanf("%d",&data);
    tail=circular_singly_list_node(data);

    for (int i = 1; i < n; i++)
    {
        printf("ENTER THE ELEMENT %d: ",i+1);
        scanf("%d",&data);
        tail=add_at_last(tail,data);
    }
    return tail;
}
void print(struct node* tail)
{
    if(tail==NULL)
        printf("EMPTY LIST");
    else
    {
        struct node* ptr=tail->next;
        do
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        } while (ptr!=tail->next);
    }
}
int main()
{
    struct node* tail=NULL;
    tail=create_list(tail);

    printf("THE CIRCULAR SINGLY LINK LIST IS :\n");
    print(tail);

    int count=0;
    struct node* ptr=tail->next;
    while (ptr!=tail)
    {
        count++;
        ptr=ptr->next;
    }
    count++;
    printf("\nTOTAL NO. OF NODES IN THE CIRCULAR SINGLY LINK LIST IS: %d",count);
    return 0;
}