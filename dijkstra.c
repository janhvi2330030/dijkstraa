#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define INF 99999

int n; // number of vertices

int minDistance(int dist[], bool visited[]) {
    int min = INF, min_index = -1;
    for (int v = 0; v < n; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf("->%d", j + 1);
}



void dijkstra(int graph[MAX][MAX], int src) {
    int dist[MAX];
    bool visited[MAX];
    int parent[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nSource\tDestination\tCost\tPath");
    for (int i = 0; i < n; i++) {
        printf("\n%d\t%d\t\t", src + 1, i + 1);
        if (dist[i] == INF) {
            printf("∞\tNo Path");
        } else if (i == src) {
            printf("0\t-");
        } else {
            printf("%d\t%d", dist[i], src + 1);
            printPath(parent, i);
        }
    }
    printf("\n");
}

int main() {
    int graph[MAX][MAX];
    int src;
    printf("Janhvi,2330030\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter the source vertex: ");
    scanf("%d", &src);
    src--; // adjust to 0-based index

    dijkstra(graph, src);

    return 0;
}
