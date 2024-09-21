#include <stdio.h>

#define MAX_SIZE 100

struct Stack {
    char data[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++(stack->top)] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->data[(stack->top)--];
}

int areParenthesesBalanced(char expr[]) {
    struct Stack *stack;
    initialize(stack);
    int i;
    char current;
    for (i = 0; expr[i] != '\0'; i++) {
        current = expr[i];
        if (current == '(' || current == '[' || current == '{') {
            push(stack, current);
        } else if (current == ')' || current == ']' || current == '}') {
            if (isEmpty(stack)) {
                return 0;
            } else {
                char popped = pop(stack);
                if ((current == ')' && popped != '(') ||
                    (current == ']' && popped != '[') ||
                    (current == '}' && popped != '{')) {
                    return 0;
                }
            }
        }
    }
    return isEmpty(stack);
}

int main() {
    char expr[MAX_SIZE];
    printf("Enter parentheses expression: ");
    scanf("%s", expr);
    if (areParenthesesBalanced(expr)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }
    return 0;
}
