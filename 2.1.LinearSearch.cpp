#include<stdio.h>

int linearSearch(int a[], int s, int key){
    int i = 0;
    while(i<s & a[i] != key)
        i++;
    if(i == s)
        return -1;
    else
        return i+1;
}

int main(){
    int a[] = {2, 3, 5, 7, 11, 13, 17, 19};
    int s = sizeof(a) / sizeof(a[0]);

    int key = 11;
    int pos = linearSearch(a, s, key);
    if(pos == -1)
        printf("Key not Found!\n");
    else
        printf("Key %d found at Position: %d\n", key, pos);
}
