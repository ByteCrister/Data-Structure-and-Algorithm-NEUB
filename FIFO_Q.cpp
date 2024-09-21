#include<stdio.h>
class fifo
{
public:
    fifo();
    void enQ(int x);
    int deQ();
    int prioQ();
    void _print();
    void _resize();

private:
    int len;
    int *a;
    int n;
    int i;
    int top;
    int _min;

};

fifo::fifo()
{
    len=4;
    a=new int[len];
    n=0;
    i=-1;
    top=0;

}

void fifo::enQ(int x)
{
    if(n==len)
    {
        printf("\nArray overflow !\n");
        _resize();
    }
    ++i;
    a[i]=x;
    ++n;
}

int fifo::deQ()
{
    if(i==-1)
    {
        printf("\nArray underflow !\n");
    }
    if(len>n*3)
    {
        _resize();
    }
    int previous=a[top];
    for(int j=0; j<n-1; j++)
    {
        a[j]=a[j+1];
    }
    n--;
    i--;

    return previous;
}

int fifo::prioQ()
{
    int _min=a[0],index;
    if(i==-1)
    {
        printf("\nArray Underflow");
    }
    else
    {
        for(int j=1; j<n; j++)
        {
            if(_min>a[j])
            {
                _min=a[j];
                index=j;
            }
        }
    }
    for(int j=index; j<n-1; j++)
    {
        a[j]=a[j+1];
    }
    --i;
    --n;
    return _min;
}
void fifo::_resize()
{
    len=2*n;
    int _max=len;

    if(_max<1)
        _max=1;

    int *b=new int[_max];
    for(int j=0; j<n; j++)
    {
        b[j]=a[j];
    }
    a=b;
    printf("\nArray resized.\n");
}

void fifo::_print()
{
    printf("[ ");
    for(int j=0; j<n; j++)
    {
        printf("%d",a[j]);
    }
    printf(" ]");
    printf("\n\n");
}
int main()
{
    fifo ob;
    ob.enQ(1);
    ob.enQ(5);
    ob.enQ(3);
    ob.enQ(4);
    printf("\nArray-> ");
    ob._print();
    ob.enQ(2);
    ob._print();
    printf("\nDequeue : %d\n",ob.deQ());
    ob.enQ(6);
    ob.enQ(7);
    ob.enQ(8);
    printf("\nArray-> ");
    ob._print();

    printf("\nPriorityQ : %d",ob.prioQ());

    printf("\nDequeue : %d",ob.deQ());
    //printf("\nDequeue : %d",ob.deQ());
    //printf("\nDequeue : %d\n",ob.deQ());

    ob._print();

    return 0;
}
