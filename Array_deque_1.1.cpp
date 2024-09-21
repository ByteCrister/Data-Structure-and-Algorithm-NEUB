#include<stdio.h>
#include<stdexcept>
class ArDeque
{
public:
    ArDeque();
    int get(int i);
    int set_(int i,int x);
    void add(int i,int x);
    int remove_(int i);
    void _print();

private:
    int *a;
    int _len;
    int j;
    int n;
    void resize_();
    void index_check(int i);
};

ArDeque::ArDeque()
{
    _len=1;
    a=new int[_len];
    j=0;
    n=0;
}

int ArDeque::get(int i)
{
    index_check(i);
    return a[(j+i)%_len];
}

int ArDeque::set_(int i,int x)
{
    index_check(i);
    int previous=a[(j+i)%_len];
    a[(j+i)%_len]=x;
    return previous;
}

void ArDeque::add(int i,int x)
{
    index_check(i);
    if(n==_len)
        resize_();

    if(i<(n/2))
    {
        j=(j-1)%_len;
        for(int k=0; k>=i-1; k++)
        {
            a[(j+k)%_len]=a[(j+k+1)%_len];
        }
    }
    else
    {
        for(int k=n; k>=i+1; k--)
        {
            a[(j+k)%_len]=a[(j+k-1)%_len];
        }
    }
    a[(j+i)%_len]=x;
    n++;
}

int ArDeque::remove_(int i)
{
    index_check(i);
    int previous=a[(j+i)%_len];
    if(i<(n/2))
    {
        for(int k=i; k>=1; k--)
        {
            a[(j+k)%_len]=a[(j+k-1)%_len];
        }
        j=(j+1)%_len;
    }
    else
    {
        for(int k=i; k<=n-2; k++)
        {
            a[(j+k)%_len]=a[(j+k+1)%_len];
        }
    }
    n--;
    if(_len>=3*n)
        resize_();
    return previous;
}

void ArDeque::resize_()
{
    _len=2*n;
    int max_=_len;
    if(max_<1)
        max_=1;
    int *b=new int[_len];
    for(int k=0; k<=n-1; k++)
    {
        b[k]=a[(j+k)%_len];
    }
    a=b;
    j=0;
}

void ArDeque::index_check(int i)
{
    if(i<0 || i>_len)
        throw std::invalid_argument("\nInvalid argument !");
}
void ArDeque::_print()
{
    printf("[ ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[(i+j)%_len]);
    }
    printf("]");
    printf("\n\n");
}
int main()
{
    ArDeque ob;

    ob.add(0,1);
    ob.add(0,2);
    ob.add(2,3);
    ob.add(3,4);
    ob.add(4,5);
    ob.add(4,6);
    ob.add(6,7);
    ob.add(7,8);
    ob._print();

    ob.add(4,11);
    ob._print();

     printf("\nGet(%d) : %d",4,ob.get(4));

     printf("\nSet(%d,%d) : %d",5,13,ob.set_(5,13));
     ob._print();

     printf("\nRemove(%d) : %d",3,ob.remove_(3));
     ob._print();

     printf("\nRemove(%d) : %d",3,ob.remove_(3));
     ob._print();

     printf("\nRemove(%d) : %d",3,ob.remove_(3));
     ob._print();

     printf("\nRemove(%d) : %d",0,ob.remove_(0));
     ob._print();

    return 0;
}
