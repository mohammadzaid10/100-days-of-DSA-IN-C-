#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Create node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = createNode(arr[0]);

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Zigzag traversal
void zigzagTraversal(Node* root) {
    if (!root) return;

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;

        int temp[100];

        for (int i = 0; i < size; i++) {
            Node* curr = queue[front++];

            int index = leftToRight ? i : (size - 1 - i);
            temp[index] = curr->data;

            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }

        for (int i = 0; i < size; i++)
            printf("%d ", temp[i]);

        leftToRight = !leftToRight; // flip direction
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, N);

    zigzagTraversal(root);

    return 0;
}