#include<stdio.h>
void merge(int ar[], int mid, int low, int high){
    int size=high-low+1;
    int ar2[size];

    int index1=low;
    int index2=mid+1;

    int index=0;
    while(index1<=mid && index2<=high){
        if(ar[index1]>ar[index2]){
            ar2[index++]=ar[index2++];
        }else{
            ar2[index++]=ar[index1++];
        }
    }

    while(index1<=mid){
        ar2[index++]=ar[index1++];
    }

    while(index2<=high){
        ar2[index++]=ar[index2++];
    }

    for(int i=0; i<size; i++){
        ar[low+i]=ar2[i];
    }
}

void mergeSort(int ar[], int low, int high){
    if(low<high){
        int mid=(low+high)/2;

        for(int i=0; i<=mid; i++){
            printf("%d ",ar[i]);
        }
        printf("\n");
        printf("[ Low-> %d, Mid-> %d ]",low,mid);
        mergeSort(ar,low,mid);

        for(int i=mid+1; i<=high; i++){
            printf("%d ",ar[i]);
        }
        printf("\n");
        printf("[ Mid-> %d, High-> %d ]",mid,high);
        mergeSort(ar,mid+1, high);

        for(int i=0; i<=high; i++){
            printf("%d ",ar[i]);
        }
        printf("\n");
        printf("[ Low-> %d, Mid-> %d, High->%d ]",low,mid,high);
        merge(ar,mid,low,high);
    }
}
int main(){

    int mainArray[]={9,1,5,2,7,3,8,0};
    for(int i=0; i<8; i++){
        printf("%d ",mainArray[i]);
    }
    printf("\n");
    mergeSort(mainArray,0,7);

    for(int i=0; i<8; i++){
        printf("%d ",mainArray[i]);
    }

    return 0;
}