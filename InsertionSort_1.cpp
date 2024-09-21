#include<stdio.h>
void insertionSort(int ar[], int n){
    for(int i=1; i<n; i++){
        int value=ar[i];
        int j=i-1;
        while(j>=0 && ar[j]>value){
            ar[j+1]=ar[j];
            j--;
            ar[j+1]=value;
        }
        
    }
}
int main(){

    printf("Enter N : ");
    int n;
    scanf("%d",&n);

    int ar[n];
    for(int i=0; i<n; i++){
        printf("[%d] -> ",i);
        scanf("%d",&ar[i]);
    }

    printf("Before sort-> ");
    for(int i=0; i<n; i++){
        printf("%d ",ar[i]);
    }

    insertionSort(ar,n);

    printf("After sort-> ");
    for(int i=0; i<n; i++){
        printf("%d ",ar[i]);
    }


    return 0;
}