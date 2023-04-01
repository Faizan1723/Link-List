#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
int main()
{
    struct node *head=NULL;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=1;
    head->link=NULL;
    
    struct node *current=malloc(sizeof(struct node));
    current->data=2;
    current->link=NULL;
    head->link=current;
    //printf("%d %d %d",head->data,head->link,head);
    //printf("%d",sizeof(struct node));

    /*METHOD 1
    IF WE WANT TO ADD ANOTHER NODE TO THE LINKED LIST IT IS POSSIBLE IN TWO WAYS
    METHOD 1 IS NOT GOOD
    WE CAN MAKE ANOTHER POINER AND THAT POINTER WILL MAKE A NODE.
    THE DATA OF THE NODE WILL BE UPDATED AND THEN WE WILL PUT THEN THE LINK VALUE OF THE 2ND NODE NODE WILL BE EQUALED TO THE VALUE OF 3RD POINTER*/
    
    //CODE

    /*struct node *current2=malloc(sizeof(struct node));
    current2->data=3;
    current2->link=NULL;
    current->link=current2;
    printf("%d",head->data);*/

    //THIS WAY WE WILL HAVE TO CREATE A NEW POINTER FOR EACH NEW NODE CREATED WHICH NOT EFFICIENT.

    /*METHOD 2
    WE WILL USE ONLY TWO PINTERS TO ADD ALL THE NODE WE WANT TO.
    FIRST LETS SEE THE CODE*/

    current=malloc(sizeof(struct node));
    current->data=3;
    current->link=NULL;
    head->link->link=current;

    printf("%d",*(head->link->link));
    return 0;
}