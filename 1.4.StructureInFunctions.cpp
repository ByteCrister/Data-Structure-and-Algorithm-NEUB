#include<stdio.h>

struct divRem{
    int div;
    int rem;
};

int sum(int x, int y){
    return x + y;
}

int sub(int x, int y){
    return x - y;
}

int prod(int x, int y){
    return x * y;
}

struct divRem division(int a, int b){
    struct divRem dr;
    dr.div = a / b;
    dr.rem = a % b;
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

    struct divRem r = division(a, b);
    printf("%-15s%d\n","Division is: ",r.div);
    printf("%-15s%d\n","Reminder is: ",r.rem);
}









