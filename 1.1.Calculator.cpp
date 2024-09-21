#include<stdio.h>

int main(){
    int a = 10, b = 3;

    int sum = a + b;
    printf("%-19s%s%d\n", "The Summation is ", ":", sum);

    int sub = a - b;
    printf("%-19s%s%d\n", "The Subtraction is ", ":", sub);

    int prod = a * b;
    printf("%-19s%s%d\n", "The Product is ", ":", prod);

    int div = a / b;
    printf("%-19s%s%d\n", "The Division is ", ":", div);

    int rem = a % b;
    printf("%-19s%s%d\n", "The Reminder is ", ":", rem);
}
