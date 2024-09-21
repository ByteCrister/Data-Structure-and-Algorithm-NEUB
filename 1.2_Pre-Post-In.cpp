#include<stdio.h>

class Node{
    public:
    int x;
    Node* left;
    Node* right;
};

class Tree{
    public:
    void PreOrder(Node*);
    void InOrder(Node*);
    void PostOrder(Node*);
    void addNode(Node*&,int);

    private:
    Node* newNode(int);
};

Node* Tree::newNode(int data){
    Node* u=new Node;
    u->x=data;
    u->left=NULL;
    u->right=NULL;
    return u;
}

void Tree::addNode(Node*& node,int data){
    if(node==NULL){
        node=newNode(data);
    }
    else if(data<node->x){
        addNode(node->left,data);
    }
    else{
        addNode(node->right,data);
    }
}

void Tree::PreOrder(Node* node){
    if(node!=NULL){
        printf("%d ",node->x);
        PreOrder(node->left);
        PreOrder(node->right);
    }
}

void Tree::PostOrder(Node* node){
    if(node!=NULL){
        PostOrder(node->left);
        PostOrder(node->right);
        printf("%d ",node->x);
    }
}

void Tree::InOrder(Node* node){
    if(node!=NULL){
        InOrder(node->left);
        printf("%d ",node->x);
        InOrder(node->right);
    }
}
int main(){

    Tree ob;
    Node* node=NULL;
    ob.addNode(node,20);
    ob.addNode(node,35);
    ob.addNode(node,82);
    ob.addNode(node,2);
    ob.addNode(node,13);
    ob.addNode(node,1);
    ob.addNode(node,11);
    ob.addNode(node,56);

    printf("\nPre-Order-travarsal->");
    ob.PreOrder(node);

    printf("\nIn-Order-travarsal->");
    ob.InOrder(node);

    printf("\nPost-Order-travarsal->");
    ob.PostOrder(node);

    return 0;
}
