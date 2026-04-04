#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int empty() {
    return front == -1;
}

// Check full
int full() {
    return (rear + 1) % MAX == front;
}

// push_front
void push_front(int x) {
    if (full()) {
        printf("Deque Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }

    deque[front] = x;
}

// push_back
void push_back(int x) {
    if (full()) {
        printf("Deque Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = x;
}

// pop_front
void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// pop_back
void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
}

// front element
int get_front() {
    if (empty())
        return -1;
    return deque[front];
}

// back element
int get_back() {
    if (empty())
        return -1;
    return deque[rear];
}

// size
int size() {
    if (empty())
        return 0;
    return (rear - front + MAX) % MAX + 1;
}

// clear
void clear() {
    front = rear = -1;
}

// display
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// reverse (O(n))
void reverse() {
    if (empty()) return;

    int temp[MAX];
    int n = size();

    int i = front;
    for (int j = 0; j < n; j++) {
        temp[j] = deque[i];
        i = (i + 1) % MAX;
    }

    // reverse array
    for (int j = 0; j < n / 2; j++) {
        int t = temp[j];
        temp[j] = temp[n - j - 1];
        temp[n - j - 1] = t;
    }

    // copy back
    front = 0;
    rear = n - 1;
    for (int j = 0; j < n; j++) {
        deque[j] = temp[j];
    }
}

// sort (ascending, O(n log n))
void sort() {
    if (empty()) return;

    int temp[MAX];
    int n = size();

    int i = front;
    for (int j = 0; j < n; j++) {
        temp[j] = deque[i];
        i = (i + 1) % MAX;
    }

    // bubble sort (simple for exam)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    front = 0;
    rear = n - 1;
    for (int j = 0; j < n; j++) {
        deque[j] = temp[j];
    }
}