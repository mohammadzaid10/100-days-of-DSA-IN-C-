#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

// Enqueue
void enqueue(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {   // empty queue
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeue
int dequeue() {
    if (front == NULL) {
        return -1;
    }

    Node* temp = front;
    int val = temp->data;

    front = front->next;

    if (front == NULL)   // queue becomes empty
        rear = NULL;

    free(temp);
    return val;
}

int main() {
    int N;
    scanf("%d", &N);

    char op[10];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'e') {   // enqueue
            scanf("%d", &x);
            enqueue(x);
        } else if (op[0] == 'd') {   // dequeue
            printf("%d\n", dequeue());
        }
    }

    return 0;
}