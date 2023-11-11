#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 100
#define MAX_M 2000
#define MAX_K 1000

typedef struct {
    int u, v, w;
} Aresta;

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void dijkstra(int N, int grafo[MAX_N + 1][MAX_N + 1], int dist[MAX_N + 1]) {
    int visitado[MAX_N + 1] = {0};

    for (int i = 1; i <= N; i++) {
        dist[i] = INT_MAX;
    }

    dist[1] = 0;

    for (int count = 0; count < N - 1; count++) {
        int min_dist = INT_MAX, min_indice;

        for (int v = 1; v <= N; v++) {
            if (!visitado[v] && dist[v] <= min_dist) {
                min_dist = dist[v];
                min_indice = v;
            }
        }

        visitado[min_indice] = 1;

        for (int v = 1; v <= N; v++) {
            if (!visitado[v] && grafo[min_indice][v] && dist[min_indice] != INT_MAX &&
                dist[min_indice] + grafo[min_indice][v] < dist[v]) {
                dist[v] = dist[min_indice] + grafo[min_indice][v];
            }
        }
    }
}

const char* pode_rabito_vencer(int N, int M, Aresta arestas[MAX_M], int K, int P, int posicoes_iniciais[MAX_K]) {
    int grafo[MAX_N + 1][MAX_N + 1] = {{0}};
    for (int i = 0; i < M; i++) {
        grafo[arestas[i].u][arestas[i].v] = arestas[i].w;
        grafo[arestas[i].v][arestas[i].u] = arestas[i].w;
    }

    int dist[MAX_N + 1];
    dijkstra(N, grafo, dist);

    qsort(posicoes_iniciais, K, sizeof(int), cmpfunc);

    for (int i = 0; i < K; i += P) {
        int ossos_mais_proximos[P];
        for (int j = 0; j < P && i + j < K; j++) {
            ossos_mais_proximos[j] = posicoes_iniciais[i + j];
        }

        for (int j = 0; j < P && i + j < K; j++) {
            if (dist[ossos_mais_proximos[j]] <= P + j) {
                return "yes";
            }
        }
    }

    return "No";
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int N, M;
        scanf("%d %d", &N, &M);

        Aresta arestas[MAX_M];
        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].w);
        }

        int K, P;
        scanf("%d %d", &K, &P);

        int posicoes_iniciais[MAX_K];
        for (int i = 0; i < K; i++) {
            scanf("%d", &posicoes_iniciais[i]);
        }

        const char* resultado = pode_rabito_vencer(N, M, arestas, K, P, posicoes_iniciais);
        printf("%s\n", resultado);
    }

    return 0;
}
