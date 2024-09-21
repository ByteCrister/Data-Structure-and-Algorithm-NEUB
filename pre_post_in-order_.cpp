#include <stdio.h>

class Node
{
public:
    int value;
    Node* left;
    Node* right;
};

class BinaryTree
{
private:
    Node* root;

public:
    BinaryTree();
    Node* createNode(int value);
    void insertNode(Node*& currentNode, int value);
    void preOrderTraversal(Node* currentNode);
    void postOrderTraversal(Node* currentNode);
    void inOrderTraversal(Node* currentNode);
};

BinaryTree::BinaryTree()
{
    root = nullptr;
}

Node* BinaryTree::createNode(int value)
{
    Node* newNode = new Node;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void BinaryTree::insertNode(Node*& currentNode, int value)
{
    if (currentNode == nullptr)
    {
        currentNode = createNode(value);
    }
    else
    {
        if (value < currentNode->value)
        {
            insertNode(currentNode->left, value);
        }
        else
        {
            insertNode(currentNode->right, value);
        }
    }
}

void BinaryTree::preOrderTraversal(Node* currentNode)
{
    if (currentNode != nullptr)
    {
        printf("%d ", currentNode->value);
        preOrderTraversal(currentNode->left);
        preOrderTraversal(currentNode->right);
    }
}

void BinaryTree::postOrderTraversal(Node* currentNode)
{
    if (currentNode != nullptr)
    {
        postOrderTraversal(currentNode->left);
        postOrderTraversal(currentNode->right);
        printf("%d ", currentNode->value);
    }
}

void BinaryTree::inOrderTraversal(Node* currentNode)
{
    if (currentNode != nullptr)
    {
        inOrderTraversal(currentNode->left);
        printf("%d ", currentNode->value);
        inOrderTraversal(currentNode->right);
    }
}

int main()
{
    BinaryTree tree;

    // Insert nodes into the binary tree
    Node* root = nullptr;
    tree.insertNode(root, 4);
    tree.insertNode(root, 2);
    tree.insertNode(root, 1);
    tree.insertNode(root, 3);
    tree.insertNode(root, 6);
    tree.insertNode(root, 5);
    tree.insertNode(root, 7);

    // Pre-order traversal
    printf("Pre-order traversal: ");
    tree.preOrderTraversal(root);
    printf("\n");

    // Post-order traversal
    printf("Post-order traversal: ");
    tree.postOrderTraversal(root);
    printf("\n");

    // In-order traversal
    printf("In-order traversal: ");
    tree.inOrderTraversal(root);
    printf("\n");

    return 0;
}
