#include<stdio.h>
struct num
{
    int x;
    char y;
    struct num *ptr;
};
int main()
{
    struct num var1;
    struct num var2;
    var1.x=15;
    var1.y='A';
    var1.ptr=NULL;
    
    var2.x=16;
    var2.y='B';
    var2.ptr=NULL;

    var1.ptr=&var2;
    printf("%d %c",var1.ptr->x,var1.ptr->y);
    return 0;
}