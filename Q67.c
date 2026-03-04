/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/
#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

int main() {
    int n, m, i;

    // Number of elements to push
    scanf("%d", &n);

    // Push n elements
    for(i = 0; i < n; i++) {
        scanf("%d", &stack[++top]);
    }

    // Number of pops
    scanf("%d", &m);

    // Perform m pops
    for(i = 0; i < m; i++) {
        if(top == -1) {
            printf("Stack Underflow\n");
            return 0;
        }
        top--;
    }

    // Display remaining stack (top to bottom)
    if(top == -1) {
        printf("Stack is Empty\n");
    } else {
        for(i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
    }

    return 0;
}