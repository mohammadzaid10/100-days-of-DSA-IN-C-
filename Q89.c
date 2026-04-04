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

// Queue for building tree
Node* queue[100];
int front = 0, rear = -1;

void enqueue(Node* node) {
    queue[++rear] = node;
}

Node* dequeue() {
    return queue[front++];
}

// Build tree
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

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

// Find LCA in Binary Tree
Node* findLCA(Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (root->data == p || root->data == q)
        return root;

    Node* left = findLCA(root->left, p, q);
    Node* right = findLCA(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;

    return (left != NULL) ? left : right;
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    Node* root = buildTree(arr, N);

    Node* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("%d", lca->data);

    return 0;
}