#include<stdio.h>

struct divRem
{
    int div;
    int rem;
};

class Calculator
{
public:
    int sum(int a, int b);
    int sub(int a, int b);
    int prod(int a, int b);
    struct divRem division(int a, int b);

private:
    int result;
};



/*****************************
* Class Methods
******************************/

int Calculator::sum(int a, int b)
{
    result = a + b;
    return result;
}

int Calculator::sub(int a, int b)
{
    result = a - b;
    return result;
}

int Calculator::prod(int a, int b)
{
    result = a * b;
    return result;
}

struct divRem Calculator::division(int a, int b)
{
    struct divRem dr;
    dr.div = a / b;
    dr.rem = a % b;
    return dr;
}


int main()
{
    Calculator cal;
    int x = 10, y = 3;
    int r = cal.sum(x, y);
    printf("%-20s%d\n","Summation is: ", r);
    r = cal.sub(x, y);
    printf("%-20s%d\n","Subtraction is: ", r);
    r = cal.prod(x, y);
    printf("%-20s%d\n","Product is: ", r);
    struct divRem r2 = cal.division(x, y);
    printf("%-20s%d\n","Division is: ", r2.div);
    printf("%-20s%d\n","Remainder is: ", r2.rem);
}






