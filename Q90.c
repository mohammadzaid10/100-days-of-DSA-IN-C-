#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Queue node with HD
typedef struct QNode {
    Node* node;
    int hd;
} QNode;

// Create node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree (level order)
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

// Vertical Order Traversal
void verticalOrder(Node* root) {
    if (!root) return;

    QNode queue[100];
    int front = 0, rear = 0;

    int map[200][100];   // store nodes
    int count[200] = {0};

    int offset = 100; // handle negative HD

    queue[rear++] = (QNode){root, 0};

    int minHD = 0, maxHD = 0;

    while (front < rear) {
        QNode temp = queue[front++];
        Node* curr = temp.node;
        int hd = temp.hd;

        map[hd + offset][count[hd + offset]++] = curr->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (curr->left)
            queue[rear++] = (QNode){curr->left, hd - 1};

        if (curr->right)
            queue[rear++] = (QNode){curr->right, hd + 1};
    }

    // Print result
    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < count[i + offset]; j++) {
            printf("%d ", map[i + offset][j]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, N);

    verticalOrder(root);

    return 0;
}