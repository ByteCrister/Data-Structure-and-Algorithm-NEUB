#include <stdio.h>
#include <algorithm>
using namespace std;
class ArrayStack{
public: 
	int length(){
		//the container size and element size n is different
		return containerSize;
	}
	ArrayStack(){ 
		//constructor makes sure that n and containerSize is 0 at the beginning
		n=0;
		containerSize=0;
	}
	void resize(){
		int size=max(1, 2*n);
		int* b=new int[size]; //new keyword allocates memory
		for(int i=0;i<n;i++){
			b[i]=a[i];
		}
		a=b;
		containerSize=size; //update containerSize
	}
	int get(int index){
		return a[index];
	}
	void add(int index, int value){
		if(n==length()){
			resize();
		}
		int i;
		for(i=index;i<n;i++){
			a[i+1]=a[i]; //make space for a[i];
		}
		a[i]=value;
		n++;
	}
	int n;
private: 
	int* a;
	int containerSize;
};

int main(){

	ArrayStack myNew;
	myNew.add(0, 5);
	myNew.add(1, 8);
	myNew.add(2, 12);
	myNew.add(3, 12);
	myNew.add(4, 12);
	myNew.add(5, 12);
	myNew.add(6, 12);
	myNew.add(7, 12);
	for(int i=0;i<myNew.n;i++){
		printf("%d\n", myNew.get(i));
	}
}
