#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int V;            // Number of vertices
    struct Node** adjList; // Array of adjacency lists
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    
    // Create an array of adjacency lists of size V
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));
    
    // Initialize each adjacency list as empty
    for (int i = 0; i < V; ++i) {
        graph->adjList[i] = NULL;
    }
    
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    
    // If the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to perform DFS traversal of the graph
void DFSUtil(struct Graph* graph, int vertex, bool* visited) {
    visited[vertex] = true;
    printf("%d ", vertex);
    
    struct Node* current = graph->adjList[vertex];
    while (current != NULL) {
        int adjacentVertex = current->data;
        if (!visited[adjacentVertex]) {
            DFSUtil(graph, adjacentVertex, visited);
        }
        current = current->next;
    }
}

void DFS(struct Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; ++i) {
        visited[i] = false;
    }
    
    printf("Depth-First Traversal starting from vertex %d:\n", startVertex);
    DFSUtil(graph, startVertex, visited);
    
    free(visited);
}

int main() {
    int V, E; // Number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    
    struct Graph* graph = createGraph(V);
    
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    
    printf("Enter the edges (format: source destination):\n");
    for (int i = 0; i < E; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        if (src < 0 || src >= V || dest < 0 || dest >= V) {
            printf("Invalid edge. Vertex index out of range.\n");
            return 1;
        }
        addEdge(graph, src, dest);
    }
    
    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);
    
    DFS(graph, startVertex);
    
    // Free dynamically allocated memory
    for (int i = 0; i < V; ++i) {
        struct Node* current = graph->adjList[i];
        while (current != NULL) {
            struct Node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->adjList);
    free(graph);
    
    return 0;
}
