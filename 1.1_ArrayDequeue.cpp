#include<stdio.h>
class dq{
    public:
    dq();
    int get(int);
    int set(int,int);
    void add(int,int);
    int remove(int);
    void print();

    private:
    int n,j,_len;
    int *a;
    void resize();
};

dq::dq(){
    n=0,j=0,_len=1;
    a=new int[_len];
}

int dq::get(int i){
    return a[(j+i)%_len];
}

int dq::set(int i,int x){
    int previous=a[(j+i)%_len];
    a[(j+i)%_len]=x;
    return previous;
}

void dq::add(int i,int x){
    if(n==_len){
        resize();
    }
    if(i<(n/2)){
        j=(j-1)%_len;
        for(int k=0; k<=i-1; k++){
            a[(j+k)%_len]=a[(j+k+1)%_len];
        }
    }
    else{
        for(int k=n; k>=i+1; k--){
            a[(j+k)%_len]=a[(j+k-1)%_len];
        }
    }
    a[(j+i)%_len]=x;
    n++;
}

int dq::remove(int i){
    int previous=a[(j+i)%_len];
    if(i<(n/2)){
        for(int k=i; k>=1; k--){
            a[(j+k)%_len]=a[(j+k-1)%_len];
        }
        j=(j+1)%_len;
    }
    else{
        for(int k=i; k<=n-2; k++){
            a[(j+k)%_len]=a[(j+k+1)%_len];
        }
    }
    n--;
    if(_len>=3*n){
        resize();
    }
    return previous;
}

void dq::resize(){
    int max=2*_len;
    if(max==0){
        max=1;
    }
    int *b=new int[max];
    for(int k=0; k<n; k++){
        b[k]=a[(j+k)%max];
    }
    j=0;
    a=b;
    _len=max;
}

void dq::print(){
    printf("[ ");
    for(int k=0; k<n; k++){
        printf("%d ",a[(j+k)%_len]);
    }
    printf("]");
    printf("\n");
}
int main(){
    dq ob;
    ob.print();

    ob.add(0,1);
    ob.add(0,2);
    ob.add(0,3);
    ob.add(0,4);
    ob.add(0,5);
    ob.add(0,6);
    ob.add(0,7);
    ob.add(0,8);

    ob.print();

    return 0;
}