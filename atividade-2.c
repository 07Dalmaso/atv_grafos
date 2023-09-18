#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 10000
#define MAX_M 100000

// Estrutura para representar um nó no grafo
typedef struct Node {
    int ilha;
    struct Node* proximo;
} Node;

// Função para adicionar um nó ao grafo
void adicionarNo(Node* grafo[], int ilha1, int ilha2) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->ilha = ilha2;
    novoNo->proximo = grafo[ilha1];
    grafo[ilha1] = novoNo;

    novoNo = (Node*)malloc(sizeof(Node));
    novoNo->ilha = ilha1;
    novoNo->proximo = grafo[ilha2];
    grafo[ilha2] = novoNo;
}

// Função para realizar a busca em largura (BFS) no grafo
int BFS(Node* grafo[], int N) {
    bool visitados[MAX_N + 1] = {false};
    int distancia[MAX_N + 1] = {0};
    int fila[MAX_N];
    int frente = 0, tras = 0;

    fila[tras] = 1;
    tras++;

    while (frente < tras) {
        int ilha = fila[frente];
        frente++;

        if (ilha == N) {
            return distancia[N];
        }

        if (!visitados[ilha]) {
            visitados[ilha] = true;

            Node* atual = grafo[ilha];
            while (atual != NULL) {
                int vizinho = atual->ilha;
                if (!visitados[vizinho]) {
                    fila[tras] = vizinho;
                    tras++;
                    distancia[vizinho] = distancia[ilha] + 1;
                }
                atual = atual->proximo;
            }
        }
    }

    return -1; // Se não for possível chegar à Ilha N
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        Node* grafo[MAX_N + 1] = {NULL};

        for (int i = 0; i < M; i++) {
            int X, Y;
            scanf("%d %d", &X, &Y);
            adicionarNo(grafo, X, Y);
        }

        int resultado = BFS(grafo, N);
        printf("casos: %d\n", resultado);
    }

    return 0;
}
