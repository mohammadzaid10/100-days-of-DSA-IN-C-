#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Create a node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graph
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS recursive function
void dfs(struct Graph* graph, int v, bool* visited) {
    visited[v] = true;
    printf("%d ", v); // Print current vertex

    struct Node* temp = graph->adjLists[v];
    while (temp) {
        if (!visited[temp->vertex])
            dfs(graph, temp->vertex, visited);
        temp = temp->next;
    }
}

// Main
int main() {
    int n, m, s;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;

    printf("DFS traversal: ");
    dfs(graph, s, visited);
    printf("\n");

    return 0;
}