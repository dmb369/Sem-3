#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

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
}

// Function to perform DFS and check for cycles
bool isCyclicUtil(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1; // Mark the current vertex as visiting
    
    struct Node* current = graph->adjList[vertex];
    while (current != NULL) {
        int adjacentVertex = current->data;
        
        if (visited[adjacentVertex] == 1) {
            // If the adjacent vertex is currently visiting, a cycle exists
            return true;
        } else if (visited[adjacentVertex] == 0 && isCyclicUtil(graph, adjacentVertex, visited)) {
            return true;
        }
        
        current = current->next;
    }
    
    visited[vertex] = 2; // Mark the current vertex as visited
    return false;
}

// Function to check if the graph has cycles
bool isCyclic(struct Graph* graph) {
    int* visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; ++i) {
        visited[i] = 0; // Initialize all vertices as unvisited
    }

    for (int i = 0; i < graph->V; ++i) {
        if (visited[i] == 0 && isCyclicUtil(graph, i, visited)) {
            return true;
        }
    }

    free(visited);
    return false;
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
    
    if (isCyclic(graph)) {
        printf("The directed graph has cycles.\n");
    } else {
        printf("The directed graph does not have cycles.\n");
    }
    
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
