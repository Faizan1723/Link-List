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
int main()
{
    struct node* tail;
    struct node* ptr;
    int data;
    tail=circular_singly_list_node(data=1);
    printf("%d",tail->data);
    return 0;
}