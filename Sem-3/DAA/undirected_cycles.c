#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
    
    // If the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to perform DFS to check for cycles
bool isCyclicUtil(struct Graph* graph, int vertex, bool* visited, int parent) {
    visited[vertex] = true;

    // Traverse all adjacent vertices
    struct Node* current = graph->adjList[vertex];
    while (current != NULL) {
        int adjacentVertex = current->data;

        // If the adjacent vertex is not visited, recursively check for a cycle
        if (!visited[adjacentVertex]) {
            if (isCyclicUtil(graph, adjacentVertex, visited, vertex))
                return true;
        }
        // If the adjacent vertex is visited and not the parent of the current vertex, a cycle exists
        else if (adjacentVertex != parent) {
            return true;
        }

        current = current->next;
    }

    return false;
}

// Function to check if the graph has cycles
bool isCyclic(struct Graph* graph) {
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; ++i) {
        visited[i] = false;
    }

    for (int i = 0; i < graph->V; ++i) {
        if (!visited[i]) {
            if (isCyclicUtil(graph, i, visited, -1)) {
                free(visited);
                return true;
            }
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
        printf("The graph has cycles.\n");
    } else {
        printf("The graph does not have cycles.\n");
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
