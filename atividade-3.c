#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 10001
#define MAX_EDGES 20001

int pai[MAX_NODES];
bool visitado[MAX_NODES];



int busca(int node) {
    if (pai[node] == -1) {
        return node;
    }
    return busca(pai[node]);
}

bool unionSets(int u, int v) {
    int a = busca(u);
    int b = busca(v);

    if (a == b) {
        return false;
    }

    pai[a] = b;
    return true;
}

bool arvore(int n, int m) {
    int i;

    if (m != n - 1) {
        return false;  
    }

    for (i = 1; i <= n; i++) {
        pai[i] = -1;
        visitado[i] = false;
    }

    for (i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (!unionSets(u, v)) {
            return false; 
        }
    }

    int componetes = 0;
    for (i = 1; i <= n; i++) {
        if (!visitado[busca(i)]) {
            visitado[busca(i)] = true;
            componetes++;
        }
    }

    return componetes == 1;
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

