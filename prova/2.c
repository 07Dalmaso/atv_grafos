#include <stdlib.h>
#include <stdio.h>

typedef struct registro
{
    int valor;
    struct registro *proximo;
} registro;

typedef struct lista
{
    int tamanho;
    struct registro *inicio;
} lista;

typedef struct vertice
{
    int visitado;
    int distanciaRaiz;
    struct lista *lista_adj;
} vertice;

typedef struct fila 
{
    int tamanho;
    struct registro *inicio;
    struct registro *fim;
}fila;

int tiraFila(fila *minhaFila)
{
    int retorno;
    retorno = minhaFila->inicio->valor;
    minhaFila->inicio = minhaFila->inicio->proximo;
    minhaFila->tamanho--;

    return retorno;
}

fila *inicia_fila()
{
    fila *nova_lista = (fila *)calloc(1, sizeof(fila));
    return nova_lista;
}

lista *inicia_lista()
{
    lista *nova_lista = (lista *)calloc(1, sizeof(lista));
    nova_lista->tamanho = 0;
    return nova_lista;
};

registro *inicia_registro()
{
    registro *novo_registro = (registro *)calloc(1, sizeof(registro));
    return novo_registro;
};

void inserir_lista(lista *minha_lista, int valor_inserir)
{
    registro *novo_registro = inicia_registro();

    novo_registro->valor = valor_inserir;
    novo_registro->proximo = NULL;

    if(minha_lista->inicio == NULL)
    {
        minha_lista->inicio = novo_registro;
        minha_lista->tamanho++;
        return;
    }

    registro *aux = minha_lista->inicio;

    while (aux->proximo != NULL)
    {
        aux = aux->proximo;
    }

    aux->proximo = novo_registro;

    minha_lista->tamanho++;
}

void montar_lista_adj(vertice *vertice, int valor)
{
    if(vertice->lista_adj == NULL)
    {
        vertice->lista_adj = inicia_lista();
    }
    inserir_lista(vertice->lista_adj, valor);
}

void coloca_fila(fila *minhaFila, int elemento)
{
    registro *novoRegistro = inicia_registro();
    novoRegistro->valor = elemento;

    if (minhaFila->inicio == NULL)
    {
        minhaFila->inicio = novoRegistro;
        minhaFila->fim = novoRegistro;
        minhaFila->tamanho++;
        return;
    }

    minhaFila->fim->proximo = novoRegistro;
    minhaFila->fim = novoRegistro;
    minhaFila->tamanho++;
}

int bfs(vertice *v, int raiz, int qtd_arestas)
{

    fila *minhaFila = inicia_fila();;
    int current;
    registro *aux;

    for (int i = 0; i < qtd_arestas; i++)
    {
        v[i].visitado = 0;
        v[i].distanciaRaiz = -1;
    };

    

    coloca_fila(minhaFila, raiz);
    v[raiz].visitado = 1;
    v[raiz].distanciaRaiz = 0;

    while (minhaFila->tamanho > 0)
    {

        current = tiraFila(minhaFila);

        aux = v[current].lista_adj->inicio;

        while (aux != NULL)
        {

            if (v[aux->valor].visitado == 0)
            {
                v[aux->valor].visitado = 1;
                coloca_fila(minhaFila, aux->valor);
                v[aux->valor].distanciaRaiz = v[current].distanciaRaiz + 1;
            }

            aux = aux->proximo;
        }
    };

    return v[qtd_arestas].distanciaRaiz;
}

int main() {
    int qtd_grafos;
    
    scanf("%d", &qtd_grafos);

    while(qtd_grafos--)
    {
            int  qtd_vertices, qtd_arestas;
            int a, b;
            int  flag = 0;
            scanf("%d %d", &qtd_vertices, &qtd_arestas);
            vertice *vertices = (vertice *)calloc(10000, sizeof(vertice));

        for(int i = 0; i < qtd_arestas; i++)
        {
            scanf("%d %d", &a, &b);
            montar_lista_adj(&vertices[a], b);
            montar_lista_adj(&vertices[b], a);
        }
        printf("casos: %d \n", bfs(vertices, 1, qtd_vertices));
    }
    return 0;
}