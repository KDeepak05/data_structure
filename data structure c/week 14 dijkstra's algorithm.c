#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

int minDistance(int dist[], bool sptSet[], int numVertices) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < numVertices; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], minIndex = v;

    return minIndex;
}

void printSolution(int dist[], int numVertices) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < numVertices; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(Graph* graph, int src) {
    int numVertices = graph->numVertices;
    int dist[MAX_VERTICES];
    bool sptSet[MAX_VERTICES];

    for (int i = 0; i < numVertices; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = minDistance(dist, sptSet, numVertices);
        sptSet[u] = true;

        for (int v = 0; v < numVertices; v++)
            if (!sptSet[v] && graph->adjacencyMatrix[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph->adjacencyMatrix[u][v] < dist[v])
                dist[v] = dist[u] + graph->adjacencyMatrix[u][v];
    }

    printSolution(dist, numVertices);
}

int main() {
    int numVertices;
    Graph graph;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    graph.numVertices = numVertices;

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph.adjacencyMatrix[i][j]);
        }
    }

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(&graph, src);

    return 0;
}
