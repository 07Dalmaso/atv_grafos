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
    int cor;
    struct lista *lista_adj;
} vertice;

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

int dfs(vertice *lista_de_vertices, int raiz, int cor)
{

    registro *aux;
    aux = lista_de_vertices[raiz].lista_adj->inicio;
    lista_de_vertices[raiz].cor = cor;
    lista_de_vertices[raiz].visitado = 1;

    while (aux != NULL){
        if (lista_de_vertices[aux->valor].visitado == 0)
        {
            if (!dfs(lista_de_vertices, aux->valor, lista_de_vertices[raiz].cor * -1))
            {
                return 0;
            };
        }
        else
        {
            if (lista_de_vertices[aux->valor].cor == lista_de_vertices[raiz].cor)
            {
                return 0;
            };
        }
        aux = aux->proximo;
    }
    return 1;
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
            vertice *vertices = (vertice *)calloc(qtd_vertices + 1, sizeof(vertice));

        for(int i = 0; i < qtd_arestas; i++)
        {
            scanf("%d %d", &a, &b);
            montar_lista_adj(&vertices[a], b);
            montar_lista_adj(&vertices[b], a);
        }

        for(int i = 1; i <= qtd_vertices; i++)
        {
            if (vertices[i].visitado == 0)
            {
                if (!dfs(vertices, i, 1))
                {
                    flag = 1;
                }
            }
        }
        if (flag)
            printf("Bugs, YESSS...!\n");
        else
            printf("No suspicious bugs found!\n");
    }
    return 0;
}