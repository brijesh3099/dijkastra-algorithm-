#include <stdio.h>
#include <limits.h>

#define V 9

struct Graph {
    int vertices;
    int** graph;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; ++i)
        graph->graph[i] = (int*)malloc(vertices * sizeof(int));
    return graph;
}

void displayResults(int* dist, int n) {
    printf("Vertex \t Distance from Source\n");
    for (int node = 0; node < n; ++node)
        printf("%d \t\t %d\n", node, dist[node]);
}

int findMinDistance(int* dist, int* sptSet, int n) {
    int minimum = INT_MAX;
    int min_index;

    for (int v = 0; v < n; ++v) {
        if (dist[v] < minimum && sptSet[v] == 0) {
            minimum = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void computeShortestPath(struct Graph* graph, int src) {
    int* dist = (int*)malloc(graph->vertices * sizeof(int));
    int* sptSet = (int*)malloc(graph->vertices * sizeof(int));

    for (int i = 0; i < graph->vertices; ++i) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < graph->vertices - 1; ++count) {
        int u = findMinDistance(dist, sptSet, graph->vertices);
        sptSet[u] = 1;

        for (int v = 0; v < graph->vertices; ++v) {
            if (!sptSet[v] && graph->graph[u][v] && dist[u] != INT_MAX && dist[u] + graph->graph[u][v] < dist[v])
                dist[v] = dist[u] + graph->graph[u][v];
        }
    }

    displayResults(dist, graph->vertices);

    free(dist);
    free(sptSet);
}

int main() {
    struct Graph* graph = createGraph(V);
    int graphData[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            graph->graph[i][j] = graphData[i][j];

    computeShortestPath(graph, 0);

    // Free allocated memory
    for (int i = 0; i < V; ++i)
        free(graph->graph[i]);
    free(graph->graph);
    free(graph);

    return 0;
}

