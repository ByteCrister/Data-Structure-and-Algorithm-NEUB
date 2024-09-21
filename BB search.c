#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i=0,n=0,s=8;
    int arr[s];
    int *ar=arr;

    //input will be continue until it takes any negative number

    for(i=0; i>=0; i++)
    {
        if(i==s)
        {
            s*=2;
            arr[s];
            *ar=arr;
        }
        printf("Array[%d]->",i);
        scanf("%d",*(ar+i));
        if(*(ar+i)<0)
        {
            break;
        }
        ++n;
    }

    return 0;
}
