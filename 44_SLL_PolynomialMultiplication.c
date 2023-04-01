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
    printf("ENTER THE NO. OF TERMS IN THE POLYNOMIAL: ");
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

struct node* multiply(struct node* head,struct node* head2)
{
    struct node* ptr1=head;
    struct node* ptr2=head2;
    struct node* head3=NULL;
    float coef;
    int expo;

    while(ptr1!=NULL)
    {
        while(ptr2!=NULL)
        {
            coef=ptr1->coef*ptr2->coef;
            expo=ptr1->expo+ptr2->expo;
            head3=insert(head3,coef,expo);
            ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
        ptr2=head2;
    }

    printf("\nTHE MULTIPLICATION OF THE TWO POLYNOMIALS IS:- \n");
    return head3;
}
struct node* simplify(struct node* head3)
{
    struct node* ptr3=head3;
    struct node* temp=NULL;
    while (ptr3->link!=NULL)
    {
        if(ptr3->expo==ptr3->link->expo)
        {
            ptr3->coef=ptr3->coef+ptr3->link->coef;
            temp=ptr3->link;
            ptr3->link=ptr3->link->link;
            free(temp);
            temp=NULL;
        }
        else
            ptr3=ptr3->link;
    }
    return head3;
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
    printf("\nENTER THE POLYNOMIAL 1:-\n");
    head=create(head);

    struct node* head2=NULL;
    printf("\nENTER THE POLYNOMIAL 2:-\n");
    head2=create(head2);

    printf("\nTHE TWO POLYNIMIALS ARE:- \n");
    print(head);
    print(head2);

    struct node* head3=NULL;
    head3=multiply(head,head2);
    head3=simplify(head3);
    print(head3);

    return 0;
}