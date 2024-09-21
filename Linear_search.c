#include<stdio.h>
int linear_search(int ar[],int key,int n)
{
    int i=0;
    while(i<n && ar[i]!=key)
        i++;
    if(i==n)
        return -1;
    else
        return i+1;
}
int main()
{
    int i=0,n,k,ar[30];
    printf("Enter number of elements : ");
    scanf("%d",&n);

    while(i<n)
    {
        printf("Array[%d]-> ",i);
        scanf("%d",&ar[i]);

        i++;
    }
    printf("\nNumber you wanna find -> ");
    scanf("%d",&k);

    int m=linear_search(ar,k,n);
    if(m==-1)
        printf("\nNumber not found");
    else
        printf("\nPosition of %d is-> %d",k,m);

    return 0;
}
