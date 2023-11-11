#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
    int visitado;
    struct lista *lista_adjacencia;
} vertice;

typedef struct lista {
    int qtd_elementos;
    struct registro *inicio;
} lista;

typedef struct registro {
    int valor;
    struct registro *proximo;
} registro;

registro *iniciarRegistro() {
    registro *novo = (registro*)calloc(1, sizeof(registro));

    return novo;
}

lista *inicializarLista() {
    lista *nova_lista = (lista*)calloc(1, sizeof(lista));

    return nova_lista;
}

void addNaLista(lista *lista, int conteudo) {
    registro *novo = iniciarRegistro();
    novo->valor = conteudo;

    if(lista->inicio == NULL) {
        lista->inicio = novo;
        lista->qtd_elementos++;

        return;
    }

    registro *aux = aux = lista->inicio;
    while(aux->proximo != NULL) {
        aux = aux->proximo;
    }
    aux->proximo = novo;
    lista->qtd_elementos++;
}

void push(vertice *vertice, int valor) {
    if(vertice->lista_adjacencia == NULL) {
        vertice->lista_adjacencia = inicializarLista();

    }
    addNaLista(vertice->lista_adjacencia, valor);
}

int dfs(vertice *vertice, int raiz, int pai) {
    vertice[raiz].visitado = 1; 
    registro *aux = vertice[raiz].lista_adjacencia->inicio; 

    if (vertice[raiz].lista_adjacencia == NULL) {
        return 0; 
    }

    while (aux != NULL) {
        if (vertice[aux->valor].visitado == 0) {
            dfs(vertice, aux->valor, raiz);
        } else if (aux->valor != pai) { 
            return 1;
        }

        aux = aux->proximo;
    }

    return 0;
}

int main() {

    int n; 
    int m; 
    int arestas;
    int u, v;
    vertice *grafo;

    scanf("%d %d", &n, &m); 
    if(m != n-1) { 
        printf("NO\n");
        return 0;
    }

    grafo = (vertice*)calloc(n+1, sizeof(vertice));

    for (int i = 1; i <= n; i++) { 
        grafo[i].visitado = 0;
    }
    
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        push(&grafo[u], v);
        push(&grafo[v], u);
    }

    for (int i = 1; i <= n; i++) { 
        if (grafo[i].visitado == 0) {
            printf("NO\n");
            return 0;
        }
    }

    int ciclo = dfs(grafo, 1, -1); 

    if (ciclo == 1) {
        printf("NO\n"); 
    } else {
        printf("YES\n");
    }

    return 0;
}