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
    int i;
    int n;
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
struct node* add(struct node* head,struct node* head2)
{
    struct node* ptr1=head;
    struct node* ptr2=head2;
    struct node* head3=NULL;
    float coef;
    int expo;

    while (ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->expo==ptr2->expo)
        {
            coef=ptr1->coef+ptr2->coef;
            head3=insert(head3,coef,ptr1->expo);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if(ptr1->expo>ptr2->expo)
        {
            head3=insert(head3,ptr1->coef,ptr1->expo);
            ptr1=ptr1->link;
        }
        else if(ptr1->expo<ptr2->expo)
        {
            head3=insert(head3,ptr2->coef,ptr2->expo);
            ptr2=ptr2->link;
        }    
    }
    while (ptr1!=NULL)
    {
        head3=insert(head3,ptr1->coef,ptr1->expo);
        ptr1=ptr1->link;
    }
    while (ptr2!=NULL)
    {
        head3=insert(head3,ptr2->coef,ptr2->expo);
        ptr2=ptr2->link;
    }
    printf("\nTHE ADDITION OF THE TWO POLYNOMIALS IS: \n");
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
    printf("\nENTER THE POLYNOMIAL 1:\n");
    head=create(head);

    struct node* head2=NULL;
    printf("\nENTER THE POLYNOMIAL 2:\n");
    head2=create(head2);

    print(head);
    print(head2);

    struct node* head3=add(head,head2);
    print(head3);
    return 0;
}