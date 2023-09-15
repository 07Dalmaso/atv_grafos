#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
    int visitado;
    int lista_adj[3000];
    int tam_lista_adj;
    int cor;
} vertice;

void mostrar_tudo(vertice *vertices, int qtd_vertices);
int dfs(vertice *vertices, int raiz, int cor);

int main() {
    int qtd_casos, qtd_vertices, qtd_arestas;
    
    scanf("%d", &qtd_casos);

    for (int caso = 1; caso <= qtd_casos; caso++) {
        scanf("%d %d", &qtd_vertices, &qtd_arestas);
        vertice *vertices = (vertice *)calloc(qtd_vertices + 1, sizeof(vertice));

        for (int i = 0; i < qtd_arestas; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            vertices[a].lista_adj[vertices[a].tam_lista_adj] = b;
            vertices[a].tam_lista_adj++;
            vertices[b].lista_adj[vertices[b].tam_lista_adj] = a;
            vertices[b].tam_lista_adj++;
        }

        int flag = 0;

        printf("Scenario #%d:\n", caso);

        for (int i = 1; i <= qtd_vertices; i++) {
            if (vertices[i].visitado == 0) {
                if (!dfs(vertices, i, 1)) {
                    flag = 1;
                    break; // Se encontrar um caso suspeito, não é necessário continuar a busca.
                }
            }
        }

        if (flag) {
            printf("Suspicious bugs found!\n");
        } else {
            printf("No suspicious bugs found!\n");
        }

        free(vertices);
    }
    return 0;
}

int dfs(vertice *vertices, int raiz, int cor) {
    vertices[raiz].visitado = 1;
    vertices[raiz].cor = cor;

    for (int i = 0; i < vertices[raiz].tam_lista_adj; i++) {
        int adj = vertices[raiz].lista_adj[i];
        if (vertices[adj].visitado == 0) {
            if (!dfs(vertices, adj, cor * -1)) {
                return 0;
            }
        } else if (vertices[raiz].cor == vertices[adj].cor) {
            return 0;
        }
    }
    return 1;
}

 