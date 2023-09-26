#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Function to perform DFS on the graph
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], bool visited[MAX_VERTICES], int V, int vertex) {
    printf("%d ", vertex); // Print the current vertex
    visited[vertex] = true; // Mark the current vertex as visited

    // Visit all adjacent vertices of the current vertex
    for (int i = 0; i < V; ++i) {
        if (graph[vertex][i] && !visited[i]) {
            DFS(graph, visited, V, i);
        }
    }
}

int main() {
    int V, E; // Number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Initialize the adjacency matrix with zeros

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
        graph[src][dest] = 1;
        // For an undirected graph, you may want to set graph[dest][src] = 1 as well.
    }

    bool visited[MAX_VERTICES] = {false}; // Array to keep track of visited vertices

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("Depth-First Traversal starting from vertex %d:\n", startVertex);
    DFS(graph, visited, V, startVertex);

    return 0;
}
