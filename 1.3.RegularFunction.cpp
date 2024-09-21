#include<stdio.h>

int sum(int a, int b){
    int result = a + b;
    return result;
}

int main(){
    int a = 10;
    int b = 3;
    int r = sum(a, b);
    printf("%d\n",r);
}
