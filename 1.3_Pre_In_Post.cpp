#include<stdio.h>
class Node{
    public:
    int x;
    Node *left,*right;
};
class BST{
    public:
    void addNode(Node*&,int);
    void PreOrder(Node*);
    void InOrder(Node*);
    void PostOrder(Node*);

    private:
    Node* newNode(int);
};

Node* BST::newNode(int data){
    Node* u=new Node;
    u->x=data;
    u->left=NULL;
    u->right=NULL;
    return u;
}

void BST::addNode(Node*& node,int data){
    if(node==NULL){
        node=newNode(data);
    }
    else if(node->x > data){
        addNode(node->left,data);
    }
    else{
        addNode(node->right,data);
    }
}

void BST::PreOrder(Node* node){
    if(node!=NULL){
        printf("%d, ",node->x);
        PreOrder(node->left);
        PreOrder(node->right);
    }
}

void BST::InOrder(Node* node){
    if(node!=NULL){
        InOrder(node->left);
        printf("%d, ",node->x);
        InOrder(node->right);
    }
}

void BST::PostOrder(Node* node){
    if(node!=NULL){
        PostOrder(node->left);
        PostOrder(node->right);
        printf("%d, ",node->x);
    }
}
int main(){
    BST ob;
    Node* node=NULL;

    ob.addNode(node,50);
    ob.addNode(node,15);
    ob.addNode(node,62);
    ob.addNode(node,5);
    ob.addNode(node,20);
    ob.addNode(node,58);
    ob.addNode(node,91);
    ob.addNode(node,3);
    ob.addNode(node,8);
    ob.addNode(node,37);
    ob.addNode(node,60);
    ob.addNode(node,24);

    printf("Pre-Order-traversal : ");
    ob.PreOrder(node);

    printf("\nIn-Order-Traversal : ");
    ob.InOrder(node);

    printf("\nPost-Order-traversal : ");
    ob.PostOrder(node);
    
    return 0;
}