/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

// Push
void push(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

// Pop
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

// Evaluate postfix
int evaluate(char postfix[]) {
    int i = 0;

    while (postfix[i] != '\0') {

        // If operand
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        }

        // If operator
        else if (postfix[i] == '+' || postfix[i] == '-' ||
                 postfix[i] == '*' || postfix[i] == '/') {

            int b = pop();
            int a = pop();
            int result;

            switch(postfix[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }

        i++;
    }

    return pop();
}

int main() {
    char postfix[100];

    printf("Enter Postfix Expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    int result = evaluate(postfix);

    printf("Result: %d\n", result);

    return 0;
}