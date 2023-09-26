#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

// Define a boolean data type
typedef int bool;
#define true 1
#define false 0

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the adjacency list for each vertex
struct AdjList {
    struct Node* head;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct AdjList* array;
};

// Create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));

    for (int i = 0; i < numVertices; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Add an edge from dest to src (since the graph is undirected)
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Depth-First Search (DFS) function to traverse the graph
void DFS(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    struct Node* currentNode = graph->array[vertex].head;

    while (currentNode != NULL) {
        int adjacentVertex = currentNode->data;
        if (!visited[adjacentVertex]) {
            DFS(graph, adjacentVertex, visited);
        }
        currentNode = currentNode->next;
    }
}

// Check if the graph has connected components
bool hasConnectedComponents(struct Graph* graph) {
    bool visited[MAX_VERTICES];
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }

    // Start DFS traversal from the first vertex
    DFS(graph, 0, visited);

    // Check if all vertices are visited
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            return false; // There is an unvisited vertex, indicating disconnected components
        }
    }

    return true; // All vertices are visited, indicating connected components
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    if (hasConnectedComponents(graph)) {
        printf("The graph has connected components.\n");
    } else {
        printf("The graph does not have connected components.\n");
    }

    return 0;
}
