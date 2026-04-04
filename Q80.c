#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Create new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for level order construction
Node* queue[100];
int front = 0, rear = -1;

// Enqueue
void enqueue(Node* node) {
    queue[++rear] = node;
}

// Dequeue
Node* dequeue() {
    return queue[front++];
}

// Build tree from level order
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        Node* curr = dequeue();

        // Left child
        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i >= n) break;

        // Right child
        if (arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, N);

    inorder(root);

    return 0;
}