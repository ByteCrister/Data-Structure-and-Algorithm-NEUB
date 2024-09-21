#include<stdio.h>
struct n{
    int x;
    struct n *next;
};

class sll{
    public:
    sll();
    void push(int data);
    int pop();
    void enqueue(int data);
    int dequeue();
    void _print();

    private:
    int N;
    struct n *head;
    struct n *tail;
    struct n *newNode(int data);
};

sll::sll(){
    N=0;
    head=NULL;
    tail=NULL;
}


struct n *sll::newNode(int data){
    struct n *node=new n;
    node->x=data;
    node->next=NULL;
    return node;
}


void sll::push(int data){
    struct n *u=newNode(data);
    u->next=head;
    head=u;
    if(N==0){
        tail=u;
    }
    N++;
}

int sll::pop(){
    if(N==0){
        return NULL;
    }
    int previous=head->x;
    head=head->next;
    N--;
    if(N==0){
        tail==NULL;
    }
    return previous;
}

void sll::enqueue(int data){
    struct n *u=newNode(data);
    if(N==0){
        head=u;
    }
    else{
        tail->next=u;
    }
    tail=u;
    N++;
}

int sll::dequeue(){
    return pop();
}

void sll::_print(){
    struct n *index=head;
    printf("[ ");
    while(index!=NULL){
        printf("%d ",index->x);
        index=index->next;
    }
    printf("]");
    printf("\n");
}
int main(){
    sll ob;

    ob.push(1);
    ob.push(2);
    ob.push(3);
    ob.push(4);
    ob.push(5);
    ob._print();
    ob.pop();
    ob._print();
    return 0;
}