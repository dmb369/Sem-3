#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent the graph
struct Graph {
    int V, E;          // Number of vertices and edges
    struct Edge* edge; // Array of edges
};

// Function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to relax an edge (used in the Bellman-Ford algorithm)
void relax(struct Graph* graph, int u, int v, int* dist) {
    if (dist[u] != INT_MAX && dist[u] + graph->edge[v].weight < dist[v]) {
        dist[v] = dist[u] + graph->edge[v].weight;
    }
}

// Function to perform the Bellman-Ford algorithm
void bellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[MAX_VERTICES];

    // Initialize distances
    for (int i = 0; i < V; ++i) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            relax(graph, u, v, dist);
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < E; ++i) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight > dist[v]) {
            printf("Graph contains a negative weight cycle.\n");
            return;
        }
    }

    // Print shortest distances
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int V, E; // Number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Graph* graph = createGraph(V, E);

    printf("Enter the edges (format: source destination weight):\n");
    for (int i = 0; i < E; ++i) {
        scanf("%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
    }

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    bellmanFord(graph, src);

    free(graph->edge);
    free(graph);

    return 0;
}
