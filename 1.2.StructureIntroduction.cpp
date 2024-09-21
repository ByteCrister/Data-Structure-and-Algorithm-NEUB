#include<stdio.h>

//Step 1 - Create a Template
struct myst{
    int a;
    float b;
};

int main(){
    //Step 2 - Create objects of the template
    struct myst ms1, ms2, ms3;

    //Step 3 - Access elements of any object
    ms1.a = 10;
    ms1.b = 3.1416;
    printf("%d\n",ms1.a);
    printf("%.4f\n",ms1.b);
}
