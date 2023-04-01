#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* add_node(struct node* head,int val)
{
    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->link=NULL;

    newnode->link=head;
    head=newnode;
    return head;
}

struct node* create_list(struct node* head,int val)
{
    while (val!=0)
    {
        head=add_node(head,val%10);
        val=val/10;
    }
    return head;
}

struct node* reverse_list(struct node* head)
{
    if(head==NULL)
        return head;
    else
    {
        struct node* current=NULL;
        struct node* next=head->link;
        head->link=NULL;
        while (next!=NULL)
        {
            current=next;
            next=next->link;
            current->link=head;
            head=current;
        }
        return head;
    }
}
struct node* new_list(struct node* head,int sum)
{
    struct node* newptr=malloc(sizeof(struct node));
    newptr->data=sum;
    newptr->link=head;
    head=newptr;

    return head;
}
struct node* add_num(struct node* head1,struct node* head2)
{
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* head3=NULL;
    int carry=0,sum;

    while (ptr1||ptr2)
    {
        sum=0;
        if(ptr1)
            sum+=ptr1->data;
        if(ptr2)
            sum+=ptr2->data;
        sum+=carry;
        carry=sum/10;
        sum=sum%10;
        head3=new_list(head3,sum);
        if(ptr1)
            ptr1=ptr1->link;
        if (ptr2)
            ptr2=ptr2->link;
    }
    if(carry)
        head3=new_list(head3,carry);
    
    return head3;
}
void result_print(struct node* head3)
{
    struct node* temp=head3;
    printf("\nTHE RESULT IS:\n");
    while (temp)
    {
        printf("%d",temp->data);
        temp=temp->link;
    }
}

void print(struct node* head)
{
    if(head==NULL)
        printf("NO NUMBER");
    else
    {
        struct node* temp=head;
        while (temp->link!=NULL)
        {
            printf("%d -> ",temp->data);
            temp=temp->link;
        }
        printf("%d",temp->data);
    }
}
int main()
{
    int a,b;
    printf("ENTER THE TWO NOS. TWO NUMBERS TO BE ADDED:-\n");
    scanf("%d%d",&a,&b);

    struct node* head1=NULL;
    printf("LINKED LIST REPRESENTATION OF FIRST NO. IS:\n");
    head1=create_list(head1,a);
    print(head1);

    struct node* head2=NULL;
    printf("\nLINKED LIST REPRESENTATION OF SECOND NO. IS:\n");
    head2=create_list(head2,b);
    print(head2);

    printf("\nREVERSED LINKED LIST ARE:\n");
    head1=reverse_list(head1);
    print(head1);
    printf("\n");
    head2=reverse_list(head2);
    print(head2);

    struct node* head3;
    head3=add_num(head1,head2);
    result_print(head3);

    return 0;
}