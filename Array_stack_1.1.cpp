#include<stdio.h>
#include<stdexcept>
class Ar_stack
{
public:
    Ar_stack();
    int get(int i);
    int set_(int i,int x);
    void add(int i,int x);
    int remove_(int i);
    void _print();

private:
    int *a;
    int len;
    int n;
    void index_check(int i);
    void resize_();
    int size_();
};

Ar_stack::Ar_stack()
{
    len=4;
    a=new int[len];
    n=0;
}

int Ar_stack::get(int i)
{
    index_check(i);
    return a[i];
}

int Ar_stack::set_(int i,int x)
{
    index_check(i);
    int previous=a[i];
    a[i]=x;
    return previous;
}

void Ar_stack::add(int i,int x)
{
    index_check(i);
    if(n==len)
        resize_();

    for(int j=size_()-1; j>=i; j--)
    {
        a[j+1]=a[j];
    }
    a[i]=x;
    n++;
}

int Ar_stack::remove_(int i)
{
    index_check(i);
    if(len>3*n)
        resize_();

    int previous=a[i];
    for(int j=i; j<size_(); j++)
    {
        a[j]=a[j+1];
    }
    n--;
    return previous;
}

int Ar_stack::size_()
{
    return n;
}

void Ar_stack::resize_()
{
    len=2*n;
    int max_=len;

    if(max_<1)
        max_=1;

    int *b=new int[max_];
    for(int i=0; i<size_(); i++)
    {
        b[i]=a[i];
    }
    a=b;
}

void Ar_stack::index_check(int i)
{
    if(i<0 || i>size_())
        throw std::invalid_argument("\nInvalid index !");
}
void Ar_stack::_print()
{
    printf("[ ");
    for(int i=0; i<size_(); i++)
    {
        printf("%d ",a[i]);
    }
    printf("]");
    printf("\n\n");
}
int main()
{
    Ar_stack ob;
    ob.add(0,1);
    ob.add(0,2);
    ob.add(0,3);
    ob._print();
    ob.add(0,4);
    ob._print();
    ob.add(0,5);
    ob._print();
    ob.add(4,6);
    ob._print();

    printf("\n -> : %d",ob.get(4));
    ob._print();
    printf("\n -> : %d",ob.set_(4,11));
    ob._print();

    printf("\nRemoved : %d",ob.remove_(1));
    ob._print();

    printf("\nRemoved : %d",ob.remove_(0));
    ob._print();

    printf("\nRemoved : %d",ob.remove_(2));
    ob._print();

    printf("\nRemoved : %d",ob.remove_(1));
    ob._print();

    return 0;
}
