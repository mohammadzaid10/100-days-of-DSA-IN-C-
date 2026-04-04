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

// Queue
Node* queue[100];
int front = 0, rear = -1;

void enqueue(Node* node) {
    queue[++rear] = node;
}

Node* dequeue() {
    return queue[front++];
}

// Build tree (level order input)
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        Node* curr = dequeue();

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i >= n) break;

        if (arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// Level Order Traversal
void levelOrder(Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (front <= rear) {
        Node* curr = dequeue();
        printf("%d ", curr->data);

        if (curr->left) enqueue(curr->left);
        if (curr->right) enqueue(curr->right);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, N);

    levelOrder(root);

    return 0;
}