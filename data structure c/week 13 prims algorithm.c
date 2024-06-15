#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

int minKey(int key[], bool mstSet[], int numVertices) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < numVertices; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], minIndex = v;
    return minIndex;
}

void printMST(int parent[], int numVertices, int graph[MAX_VERTICES][MAX_VERTICES]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < numVertices; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(Graph* graph) {
    int numVertices = graph->numVertices;
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];

    for (int i = 0; i < numVertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = minKey(key, mstSet, numVertices);
        mstSet[u] = true;

        for (int v = 0; v < numVertices; v++) {
            if (graph->adjacencyMatrix[u][v] && mstSet[v] == false && graph->adjacencyMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->adjacencyMatrix[u][v];
            }
        }
    }

    printMST(parent, numVertices, graph->adjacencyMatrix);
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

    primMST(&graph);

    return 0;
}
