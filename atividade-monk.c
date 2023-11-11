// BFS
#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int distanciaRaiz;
    struct lista *listaAdj;
} vertice;

typedef struct lista
{
    int quantidadeElementos;
    struct registro *inicio;
} lista;

typedef struct registro
{
    int valor;
    struct registro *proximo;
} registro;

typedef struct fila
{
    int tamanho;
    struct registro *inicio;
    struct registro *fim;

} fila;

int tiraFila(fila *minhaFila)
{
    int retorno;
    retorno = minhaFila->inicio->valor;
    minhaFila->inicio = minhaFila->inicio->proximo;
    minhaFila->tamanho--;

    return retorno;
}

fila *iniciaFila()
{
    fila *novo;

    novo = (fila *)calloc(1, sizeof(fila));

    return novo;
}

registro *iniciaRegistro()
{
    registro *novo;

    novo = (registro *)calloc(1, sizeof(registro));

    return novo;
    
}

void colocaFila(fila *minhaFila, int elemento)
{
    registro *novoRegistro = iniciaRegistro();
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

lista *iniciaLista()
{
    lista *novo;

    novo = (lista *)calloc(1, sizeof(lista));

    return novo;
}

void mostraFila(fila *filaRecebida)
{
    registro *aux;

    aux = filaRecebida->inicio;

    printf("Fila: ");
    if (aux->proximo == NULL)
    {
        printf("%d, ", aux->valor);
        return;
    }

    while (aux->proximo != NULL)
    {

        printf("%d, ", aux->valor);
        aux = aux->proximo;
    };
}

int bfs(vertice *v, int raiz, int qtd_arestas)
{

    fila *minhaFila = iniciaFila();;
    int current;
    registro *aux;

    for (int i = 0; i < qtd_arestas; i++)
    {
        v[i].visitado = 0;
        v[i].distanciaRaiz = -1;
    };

    

    colocaFila(minhaFila, raiz);
    v[raiz].visitado = 1;
    v[raiz].distanciaRaiz = 0;

    while (minhaFila->tamanho > 0)
    {

        current = tiraFila(minhaFila);

        aux = v[current].listaAdj->inicio;

        while (aux != NULL)
        {

            if (v[aux->valor].visitado == 0)
            {
                v[aux->valor].visitado = 1;
                colocaFila(minhaFila, aux->valor);
                v[aux->valor].distanciaRaiz = v[current].distanciaRaiz + 1;
            }

            aux = aux->proximo;
        }
    };

    return v[qtd_arestas].distanciaRaiz;
}

int incluiLista(lista *l, int x)
{
    registro *novoRegistro;
    novoRegistro = iniciaRegistro();
    novoRegistro->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novoRegistro;
        l->quantidadeElementos++;
        return 0;
    }

    registro *aux = l->inicio;

    while (aux->proximo != NULL)
    {
        aux = aux->proximo;
    }

    aux->proximo = novoRegistro;
    l->quantidadeElementos++;
    return 1;
}

void push(vertice *v, int x)
{
    if (v->listaAdj == NULL)
    {
        v->listaAdj = iniciaLista();
    }

    incluiLista(v->listaAdj, x);
}

int main()
{
    int qtd_vertices, qtd_arestas;
    int i, a, b, qtd_cc = 0;
    vertice *vertices;

    scanf("%d", &qtd_cc);
    int aux = qtd_cc;
    while (aux--)
    {
        scanf("%d %d", &qtd_vertices, &qtd_arestas);

        vertices = (vertice *)calloc(10000, sizeof(vertice));

        for (i = 0; i < qtd_arestas; i++)
        {
            scanf("%d %d", &a, &b);
            push(&vertices[a], b);
            push(&vertices[b], a);
        };

        printf("%d \n", bfs(vertices, 1, qtd_vertices));
    }

    return 0;
}