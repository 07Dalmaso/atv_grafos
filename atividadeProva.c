#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int cor;
    struct lista *lista_adj;
} vertice;

typedef struct lista
{
    int tamanho;
    struct registro *inicio;
} lista;

typedef struct registro
{
    int valor;
    struct registro *proximo;
} registro;

lista *inicializa_lista()
{
    lista *nova_lista = (lista *)calloc(1, sizeof(lista));
    nova_lista->tamanho = 0;
    return nova_lista;
};

registro *inicializa_registro()
{
    registro *nova_registro = (registro *)calloc(1, sizeof(registro));
    return nova_registro;
};

void inserir_lista(lista *minha_lista, int valor_para_inserir)
{
    
    registro *novo_registro = inicializa_registro();

    novo_registro->valor = valor_para_inserir;
    novo_registro->proximo = NULL;

    if (minha_lista->inicio == NULL) {
        minha_lista->inicio = novo_registro;
        minha_lista->tamanho++;
        return;
    }

    registro *aux;
    aux = minha_lista->inicio;

    while (aux->proximo != NULL)
    {
        aux = aux->proximo;
    }

    aux->proximo = novo_registro;

    minha_lista->tamanho++;
}

void mostrar_lista(vertice *vertice)
{
    registro *aux;
    aux = vertice->lista_adj->inicio;

    while (aux != NULL)
    {
        printf("%d, ", aux->valor);

        aux = aux->proximo;
    }

    printf("\n");
}

void colocar_na_lista_de_adjacencia(vertice *vertice, int valor) {
    if (vertice->lista_adj == NULL)
    {
        vertice->lista_adj = inicializa_lista();
    }
    inserir_lista(vertice->lista_adj, valor);
}

void dfs(vertice *vertices, int vertice_atual, int vertice_anterior) {
    
    vertices[vertice_atual].visitado = 1; // Marcar o vértice como visitado
    printf("%d ", vertice_atual); // Imprimir o vértice visitado

    // Percorrer todos os vértices adjacentes
    registro *aux = vertices[vertice_atual].lista_adj->inicio;
    while (aux != NULL) {
        int adjacente = aux->valor;
        if (!vertices[adjacente].visitado) {
            // Chamar DFS recursivamente para os vértices não visitados
            dfs(vertices, adjacente, vertice_atual);
        }else if(aux->valor != vertice_anterior){
            printf("ciclos");
            break;
        }
        aux = aux->proximo;
    }
}

int main() {
    int qtd_casos;

    scanf("%d", &qtd_casos);

    while (qtd_casos--){
        int qtd_vertices, qtd_arestas;
        int a, b;
        scanf("%d %d", &qtd_vertices, &qtd_arestas);

        if(qtd_vertices -1 != qtd_arestas){
            printf("Não é arvore");
            return 0;
        }

        vertice *vertices = (vertice *)calloc(qtd_vertices + 1, sizeof(vertice));

        for (int i = 0; i < qtd_arestas; i++)
        {
            scanf("%d %d", &a, &b);
            colocar_na_lista_de_adjacencia(&vertices[a], b);
            colocar_na_lista_de_adjacencia(&vertices[b], a);
        }

        for (int i = 1; i <= qtd_vertices; i++)
        {
            printf("Lista de adjacência do %i: ", i);
            mostrar_lista(&vertices[i]);
        }

        for (int i = 1; i <= qtd_vertices; i++) {
            if (!vertices[i].visitado) {
                printf("DFS a partir do vértice %d: ", i);
                dfs(vertices, i, -1);
                printf("\n");
            }
        }
    }

    return 0;
}