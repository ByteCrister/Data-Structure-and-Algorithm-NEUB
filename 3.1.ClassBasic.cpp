#include<stdio.h>

class demo
{
public:
    int a;
    float b;

    int sum(int x, int y)
    {
        return x + y;
    }
};

int main()
{
    demo ob;
    demo ob2;
    ob.a = 10;
    ob.b = 3.1416;
    int result = ob.sum(30, 40);
    printf("%d %0.4f %d\n",ob.a, ob.b, result);
}
