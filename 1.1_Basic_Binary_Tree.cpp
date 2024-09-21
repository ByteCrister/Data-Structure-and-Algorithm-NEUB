#include <stdio.h>

class Node
{
public:
    int value;
    Node* left;
    Node* right;
    Node* parent;
};

class BinaryTree
{
private:
    Node* root;

public:
    BinaryTree()
    {
        root = nullptr;
    }

    void setRoot(Node* node)
    {
        root = node;
    }

    Node* initialize()
    {
        root = nullptr;
        return root;
    }

    int depth(Node* u)
    {
        int d = 0;
        while (u != root)
        {
            u = u->parent;
            d++;
        }
        return d;
    }

    int size(Node* u)
    {
        if (u == nullptr)
            return 0;
        return 1 + size(u->left) + size(u->right);
    }

    int height(Node* u)
    {
        if (u == nullptr)
            return 0;
        int leftHeight = height(u->left);
        int rightHeight = height(u->right);
        int maxHeight;
        if (leftHeight > rightHeight)
        {
            maxHeight = leftHeight;
        }
        else
        {
            maxHeight = rightHeight;
        }
        return 1 + maxHeight;
    }

    void printElements(Node* u)
    {
        if (u == nullptr)
            return;
        printElements(u->left);
        printf("%d ", u->value);
        printElements(u->right);
    }
};

int main()
{
    BinaryTree tree;

    // Create nodes and build the binary tree
    Node* root = new Node;
    root->value = 1;
    Node* node2 = new Node;
    node2->value = 2;
    Node* node3 = new Node;
    node3->value = 3;
    Node* node4 = new Node;
    node4->value = 4;

    root->left = node2;
    root->right = node3;

    node3->left=node4;

    node2->parent = root;
    node3->parent = root;
    node4->parent=node3;

    // Set the parent pointers correctly
    node2->left = nullptr;
    node2->right = nullptr;

    node3->right = nullptr;
    node4->left=NULL;
    node4->right=NULL;

    // Set the root of the binary tree
    tree.setRoot(root);

    // Print the elements of the binary tree
    printf("Elements of the binary tree: ");
    tree.printElements(root);
    printf("\n");

    // Calculate and print the depth of the nodes
    printf("Depth of root: %d\n", tree.depth(root));
    printf("Depth of node2: %d\n", tree.depth(node2));
    printf("Depth of node3: %d\n", tree.depth(node3));

    // Calculate and print the size of the tree
    printf("Size of the tree: %d\n", tree.size(root));

    // Calculate and print the height of the tree
    printf("Height of the tree: %d\n", tree.height(root));

    return 0;
}
