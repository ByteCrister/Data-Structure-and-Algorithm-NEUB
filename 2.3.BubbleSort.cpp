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
    int a[] = {5, 7, 11, 2, 3, 13, 19, 17};
    int s = sizeof(a) / sizeof(a[0]);

    bubbleSort(a, s);

    int i;
    for(i=0; i<s; i++)
        printf("%d ", a[i]);
    printf("\n");
}
