#include <stdio.h>
#include <stdlib.h>

// Function to create a graph using an adjacency matrix
int** createGraph(int V) {
    int** graph = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; ++i) {
        graph[i] = (int*)malloc(V * sizeof(int));
    }
    
    // Initialize the matrix with zeros (no edges)
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            graph[i][j] = 0;
        }
    }
    
    return graph;
}

// Function to add an edge to the graph
void addEdge(int** graph, int src, int dest) {
    // Assuming an undirected graph, set both src->dest and dest->src to 1
    graph[src][dest] = 1;
    graph[dest][src] = 1;
}

// Function to print the graph
void printGraph(int** graph, int V) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V, E; // Number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    
    int** graph = createGraph(V);
    
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
    
    printf("Graph created:\n");
    printGraph(graph, V);
    
    // Free dynamically allocated memory
    for (int i = 0; i < V; ++i) {
        free(graph[i]);
    }
    free(graph);
    
    return 0;
}
