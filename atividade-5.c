#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 10001

int grafo[MAX_NODES][MAX_NODES];
bool visitado[MAX_NODES];

int dfs(int no) {
    visitado[no] = true;
    int profundidade_maxima = 0;

    for (int i = 1; i < MAX_NODES; ++i) {
        if (grafo[no][i] && !visitado[i]) {
            int profundidade = 1 + dfs(i);
            if (profundidade > profundidade_maxima) {
                profundidade_maxima = profundidade;
            }
        }
    }

    return profundidade_maxima;
}

int comprimento_caminho_mais_longo(int n, int arestas[][2]) {
    for (int i = 0; i < MAX_NODES; ++i) {
        visitado[i] = false;
        for (int j = 0; j < MAX_NODES; ++j) {
            grafo[i][j] = 0;
        }
    }

    // Criando a matriz de adjacência
    for (int i = 0; i < n - 1; ++i) {
        int u = arestas[i][0];
        int v = arestas[i][1];
        grafo[u][v] = grafo[v][u] = 1;
    }

    int comprimento_maximo = 0;

    for (int no_inicial = 1; no_inicial <= n; ++no_inicial) {
        for (int i = 0; i < MAX_NODES; ++i) {
            visitado[i] = false;
        }

        int comprimento = dfs(no_inicial);
        if (comprimento > comprimento_maximo) {
            comprimento_maximo = comprimento;
        }
    }

    return comprimento_maximo;
}

int main() {
    int n;
    scanf("%d", &n);

    int arestas[MAX_NODES - 1][2];
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &arestas[i][0], &arestas[i][1]);
    }

    int resultado = comprimento_caminho_mais_longo(n, arestas);
    printf("%d\n", resultado);

    return 0;
}
