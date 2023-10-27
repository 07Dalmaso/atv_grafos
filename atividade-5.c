#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 10001

int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

int dfs(int node) {
    visited[node] = true;
    int max_depth = 0;

    for (int i = 1; i < MAX_NODES; ++i) {
        if (graph[node][i] && !visited[i]) {
            int depth = 1 + dfs(i);
            if (depth > max_depth) {
                max_depth = depth;
            }
        }
    }

    return max_depth;
}

int longest_path_length(int n, int edges[][2]) {
    for (int i = 0; i < MAX_NODES; ++i) {
        visited[i] = false;
        for (int j = 0; j < MAX_NODES; ++j) {
            graph[i][j] = 0;
        }
    }

    // Creating the adjacency matrix
    for (int i = 0; i < n - 1; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u][v] = graph[v][u] = 1;
    }

    int max_length = 0;

    for (int start_node = 1; start_node <= n; ++start_node) {
        for (int i = 0; i < MAX_NODES; ++i) {
            visited[i] = false;
        }

        int length = dfs(start_node);
        if (length > max_length) {
            max_length = length;
        }
    }

    return max_length;
}

int main() {
    int n;
    scanf("%d", &n);

    int edges[MAX_NODES - 1][2];
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int result = longest_path_length(n, edges);
    printf("%d\n", result);

    return 0;
}
