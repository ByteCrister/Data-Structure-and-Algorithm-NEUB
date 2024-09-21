#include<stdio.h>
#include<stdlib.h>

struct divRem{
    int div;
    int rem;
};

int sum(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int prod(int a, int b){
    return a * b;
}

struct divRem * division(int a, int b){
    struct divRem *dr;
    dr = (struct divRem *)malloc(sizeof(struct divRem));
    dr->div = a / b;
    dr->rem = a % b;
    return dr;
}

int main(){
    int a = 10;
    int b = 3;

    int result = sum(a, b);
    printf("%-15s%d\n","Sum is: ",result);

    result = sub(a, b);
    printf("%-15s%d\n","Sub is: ",result);

    result = prod(a, b);
    printf("%-15s%d\n","Product is: ",result);

    struct divRem *r = division(a, b);
    printf("%-15s%d\n","Division is: ",r->div);
    printf("%-15s%d\n","Reminder is: ",r->rem);
}
