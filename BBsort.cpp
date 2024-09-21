#include<stdio.h>

void bubbleSort(int a[], int s){
    int i;
    int j;
    int temp;
    for(i=0; i<=s-2; i++){
        for(j=s-1; j >= i+1; j--){
            if(a[j] < a[j-1]){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
}
int main(){
    int a[],i=0;
    while(a[i]!=' ')
    {
        printf("Array[%d]-> ",i);
        scanf("%d",a[i]);
        i++;
    }
    int s = sizeof(a) / sizeof(a[0]);

    bubbleSort(a, s);

    for(i=0; i<s; i++)
        printf("%d ", a[i]);
    printf("\n");
}

