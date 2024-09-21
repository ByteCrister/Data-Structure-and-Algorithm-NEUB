#include<stdio.h>

class treeNode{
public:
    int x;
    treeNode *parent;
    treeNode *left;
    treeNode *right;
};

class binaryTree{
public:
    //Variables
    treeNode *r;    //Root of the tree
    int n;          //Number of nodes in the tree

    //Regular Methods
    binaryTree();
    treeNode* newNode(int);
    treeNode* buildT_NegBased(int[], int*, treeNode*);

    //Traversal Methods
    void preorderRecursive(treeNode*);
    void inorderRecursive(treeNode*);
    void postorderRecursive(treeNode*);
    void preorderIterative();       //Always traverse from root
};



/******************************
* Regular Methods
*******************************/
binaryTree::binaryTree(){
    r = NULL;
    n = 0;
}

treeNode* binaryTree::newNode(int data){
    treeNode *node = new treeNode();
    node->x = data;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

treeNode* binaryTree::buildT_NegBased(int arr[], int *currentIndex, treeNode *p){
    
    *currentIndex = *currentIndex + 1;
    //printf("%d\n", *currentIndex);

    if(arr[*currentIndex] == -1)
        return NULL;

    //Create the Node
    treeNode *u = newNode(arr[*currentIndex]);
    n = n + 1;

    //Update the Root
    if(*currentIndex == 0)
        r = u;

   //Update parent of the current node
   u->parent = p;

   //Recursive call for the left and right child
   u->left = buildT_NegBased(arr, currentIndex, u);
   u->right = buildT_NegBased(arr, currentIndex, u);
   return u;
}



/******************************
* Traversal Methods
*******************************/

void binaryTree::preorderRecursive(treeNode *u){
    if(u == NULL)
        return;
    printf("%d ", u->x);
    preorderRecursive(u->left);
    preorderRecursive(u->right);
}

void binaryTree::inorderRecursive(treeNode *u){
    if(u == NULL)
        return;
    inorderRecursive(u->left);
    printf("%d ", u->x);
    inorderRecursive(u->right);
}

void binaryTree::postorderRecursive(treeNode *u){
    if(u == NULL)
        return;
    postorderRecursive(u->left);
    postorderRecursive(u->right);
    printf("%d ", u->x);
}

void binaryTree::preorderIterative(){
    treeNode *u = r;
    treeNode *prev = NULL;
    treeNode *next;

    while( u != NULL){
        if(prev == u->parent){
            printf("%d ", u->x);    //Print only if the node comes from the parent
            if(u->left != NULL)
                next = u->left;
            else if(u->right != NULL)
                next = u->right;
            else
                next = u->parent;
        }
        else if(prev == u->left){
            if(u->right != NULL)
                next = u->right;
            else
                next = u->parent;
        }
        else
            next = u->parent;

        prev = u;
        u = next;
    }
}



/******************************
* main
*******************************/

int main()
{
    binaryTree ob;

    //This is the tree we had seen in our class (Slide-11)
    int arr[] = {1, 2, 4, -1, 7, -1, -1, -1,
                    3, 5, -1, -1, 6, 8, -1, 10, -1, -1, 9, -1, -1};

    //Tree building requires 3 parameters: array, currentIndex, parent
    int currentIndex = -1;  //Stars from -1; increments as recursive call occurs
    printf("Building the tree...\n");
    treeNode *r = ob.buildT_NegBased(arr, &currentIndex, NULL);
    printf("The tree was build successfully with number of nodes = %d\n", ob.n);
    printf("The root of the tree is: %d\n\n", r->x);

    //Tree Traversal
    printf("Preorder Traversal: ");
    ob.preorderRecursive(r);

    printf("\nInorder Traversal: ");
    ob.inorderRecursive(r);

    printf("\nPostorder Traversal: ");
    ob.postorderRecursive(r);

    printf("\nPreorder Traversal (Iterative): ");
    ob.preorderIterative();
    printf("\n\n");
}
