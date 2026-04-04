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

// Insert into BST
Node* insert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

// Find LCA in BST
Node* findLCA(Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    // Both nodes in left subtree
    if (p < root->data && q < root->data)
        return findLCA(root->left, p, q);

    // Both nodes in right subtree
    if (p > root->data && q > root->data)
        return findLCA(root->right, p, q);

    // Split point → this is LCA
    return root;
}

int main() {
    int N;
    scanf("%d", &N);

    Node* root = NULL;

    // Build BST
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    Node* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("%d", lca->data);

    return 0;
}