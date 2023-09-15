#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 10001
#define MAX_EDGES 20001

int parent[MAX_NODES];
bool visited[MAX_NODES];



int find(int node) {
    if (parent[node] == -1) {
        return node;
    }
    return find(parent[node]);
}

bool unionSets(int u, int v) {
    int a = find(u);
    int b = find(v);

    if (a == b) {
        return false;  // There is a cycle
    }

    parent[a] = b;
    return true;
}

bool arvore(int n, int m) {
    int i;

    if (m != n - 1) {
        return false;  // A tree must have exactly n-1 edges
    }

    for (i = 1; i <= n; i++) {
        parent[i] = -1;
        visited[i] = false;
    }

    for (i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (!unionSets(u, v)) {
            return false;  // There is a cycle
        }
    }

    int componetes = 0;
    for (i = 1; i <= n; i++) {
        if (!visited[find(i)]) {
            visited[find(i)] = true;
            componetes++;
        }
    }

    return componetes == 1;  // If there is only one connected component, it's a tree
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    if (arvore(n, m)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

