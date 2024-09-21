#include<stdio.h>

struct divRem{
    int div;
    int rem;
};

class Calculator{
public:
    Calculator(int, int);
    int sum();
    int sub();
    int prod();
    struct divRem division();

private:
    int a, b;
};



/*****************************
* Class Methods
******************************/

Calculator::Calculator(int x, int y){
    a = x;
    b = y;
}

int Calculator::sum(){
    return a + b;
}

int Calculator::sub(){
    return a - b;
}

int Calculator::prod(){
    return a * b;
}

struct divRem Calculator::division(){
    struct divRem dr;
    dr.div = a / b;
    dr.rem = a % b;
    return dr;
}





int main(){
    int x = 10, y = 3;
    Calculator cal(x, y);

    int r = cal.sum();
    printf("%-20s%d\n","Summation is: ", r);

    r = cal.sub();
    printf("%-20s%d\n","Subtraction is: ", r);

    r = cal.prod();
    printf("%-20s%d\n","Product is: ", r);

    struct divRem r2 = cal.division();

    printf("%-20s%d\n","Division is: ", r2.div);

    printf("%-20s%d\n","Remainder is: ", r2.rem);
}






