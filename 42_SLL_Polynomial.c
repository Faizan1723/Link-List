#include<stdio.h>
#include<stdlib.h>
struct node
{
    float coef;
    int expo;
    struct node* link;
};
struct node* insert(struct node* head, float coef,int expo )
{
    struct node* temp;
    struct node* newp=(struct node*)malloc(sizeof(struct node));
    newp->coef=coef;
    newp->expo=expo;
    newp->link=NULL;

    if(head==NULL || expo>head->expo)
    {
        newp->link=head;
        head=newp;
    }
    else
    {
        temp=head;
        while(temp->link!=NULL && temp->link->expo>expo)
        {
            temp=temp->link;
        }
        newp->link=temp->link;
        temp->link=newp;
    }  
    return head;
}
struct node*create(struct node* head)
{
    int n;
    int i;
    float coef;
    int expo;
    printf("ENTER THE NO. OF TERMS IN THE POLYNOMIALS: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("ENTER THE COEFFICIENT OF TERM %d: ",i+1);
        scanf("%f",&coef);
        printf("ENTER THE EXPONENT OF TERM %d: ",i+1);
        scanf("%d",&expo);

        head=insert(head,coef,expo);
    }
    return head;
}
void print(struct node* head)
{
    if(head==NULL)
        printf("NO PLYNOMIAL\n");
    else
    {
        struct node* temp=head;
        while (temp!=NULL)
        {  
            printf("(%.1fx^%d)",temp->coef,temp->expo);
            temp=temp->link;
            if(temp!=NULL)
                printf("+");
            else
                printf("\n");
        }
    }
}
int main()
{
    struct node* head=NULL;
    printf("ENTER THE POLYNOMIAL:\n");
    head=create(head);
    print(head);

    return 0;
}