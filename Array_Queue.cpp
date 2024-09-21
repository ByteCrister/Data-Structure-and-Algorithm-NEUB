#include<stdio.h>

class AryQ{

public:
     AryQ();
     void _add(int x);
     int _remove();
     void _print();

private:
     int *a;
     int _len;
     int j;
     int n;
     void _resize();
};

AryQ::AryQ(){

     _len=1;
     a=new int[_len];
     j=0;
     n=0;
}

void AryQ::_add(int x){

     if(n+1>_len){
          _resize();
     }
     a[(j+n)%_len]=x;
     n++;
}

int AryQ::_remove(){

     int previous=a[j];
     j=(j+1)%_len;
     n--;
     if(_len>=3*n){
          _resize();
     }
     return previous;
}

void AryQ::_resize(){

     int _max=2*n;
     if(_max==0){
          _max=1;
     }
     int *b=new int[_max];
     for(int k=0; k<n; k++){

          b[k]=a[(j+k)%_len];
     }
     a=b;
     j=0;
     _len=_max;
}

void AryQ::_print(){

     printf("[ ");
     for(int i=0; i<n; i++){
          printf("%d ",a[(j+i)%_len]);
     }
     printf("]");
     printf("\n");
     printf("\n");
}
int main(){

     AryQ ob;

     ob._print();

     printf("Add(%d)->",1);
     ob._add(1);
     ob._print();

     printf("Add(%d)->",2);
     ob._add(2);
     ob._print();

     printf("Add(%d)->",3);
     ob._add(3);
     ob._print();

     printf("Add(%d)->",4);
     ob._add(4);
     ob._print();

     printf("Add(%d)->",5);
     ob._add(5);
     ob._print();

     printf("Removed (%d) ->",ob._remove());
     ob._print();

     printf("Removed (%d) ->",ob._remove());
     ob._print();

     printf("Removed (%d) ->",ob._remove());
     ob._print();

     printf("Removed (%d) ->",ob._remove());
     ob._print();

     printf("Removed (%d) ->",ob._remove());
     ob._print();

     return 0;
}
