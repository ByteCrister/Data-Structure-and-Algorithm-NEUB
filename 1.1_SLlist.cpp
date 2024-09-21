#include <stdio.h>

class Node
{
public:
    int x;
    Node *next;
};

class sll
{
public:
    sll();

    void push(int);
    int pop();

    void enqueue(int);
    int dequeue();

    void _print();

private:
    int n;
    Node *head;
    Node *tail;
    Node *newNode(int);
};

sll::sll()
{
    n = 0;
    head = NULL;
    tail = NULL;
}

Node *sll::newNode(int data)
{
    Node *node = new Node;
    node->x = data;
    node->next = NULL;
    return node;
}

void sll::push(int data)
{
    Node *u = newNode(data);
    u->next = head;
    head = u;
    n++;
    if (n == 0)
        tail = u;
}

int sll::pop()
{
    if (n == 0)
        return NULL;

    int previous = head->x;
    head = head->next;
    n--;

    if (n == 0)
        tail = NULL;

    return previous;
}

void sll::enqueue(int data)
{
    Node *u = newNode(data);
    if (n == 0)
    {
        head = u;
    }
    else
    {
        tail->next = u;
    }
    tail = u;
    n++;
}

int sll::dequeue()
{
    return pop();
}

void sll::_print()
{
    Node *index = head;
    printf("[ ");
    while (index != NULL)
    {
        printf("%d ", index->x);
        index = index->next;
    }
    printf("]");
    printf("\n");
}
int main()
{
    sll ob;
    printf("Initial List: ");
    ob._print();

    ob.push(1);
    ob.push(2);
    ob.push(3);
    ob.push(4);
    ob.push(5);
    ob.push(6);
    ob.push(7);

    printf("\nAfter adding elements in the List-> ");
    ob._print();

    printf("\nPoped : %d", ob.pop());
    printf("\nPoped : %d", ob.pop());
    printf("\nPoped : %d", ob.pop());

    printf("\nCurrent List-> ");
    ob._print();

    ob.enqueue(10);
    ob.enqueue(20);
    ob.enqueue(30);
    ob.enqueue(40);
    ob.enqueue(50);

    printf("\nAfter adding elements in the List-> ");
    ob._print();

    return 0;
}
