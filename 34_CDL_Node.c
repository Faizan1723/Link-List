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
int main()
{
    struct node* tail;
    int data=1;
    tail=circular_doubly_list_node(data);

    printf("%d",tail->data);
    return 0;
}