#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* prev;
    int data;
    struct node* next; 
};
struct node* add_node(struct node *head,int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    
    head=temp;
    return head;
}

struct node * add_at_end(struct node* head,int data)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    struct node* tp=head;
    while (tp->next!=NULL)
    {
        tp=tp->next;
    }
    tp->next=temp;
    temp->prev=tp;
    return head;
}
struct node* create_list(struct node *head)
{
    int n,data,i;
    printf("ENTER THE NO. OF NODES YOU WANT TO MAKE: ");
    scanf("%d",&n);

    if(n==0)
        return head;
    printf("ENTER THE ELEMENT FOR NODE 1: ");
    scanf("%d",&data);
    head=add_node(head,data);

    for(i=1;i<n;i++)
    {
        printf("ENTER THE ELEMENT FOR THE NODE %d: ",i+1);
        scanf("%d",&data);
        head=add_at_end(head,data);
    }
    return head;
}
int main()
{
    struct node *head=NULL;
    struct node* ptr;
    head=create_list(head);

    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}