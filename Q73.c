#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int x) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {  // First element
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = x;
}

// Dequeue operation
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    if (front == rear) {  // Only one element
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display queue
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}