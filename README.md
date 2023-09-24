# Teoria Grafos 

## Primeira prova 

### Grafo 
- Um grafo é uma estrutura composta por dois conjuntos: o primeiro conjunto contém vértices não ordenados e aleatórios, enquanto o segundo é formado por pares de vértices. 

G ={ V, A}

V={1,2,4,6,5}

A ={(1,2),(4,6),(2,5)}

### Quando o grafo é uma arvore?

- Caso a quantidade de arestas for igual a de vértices menos **1**, e não pode ocorrer ciclos.
- Toda arvore é um grafo, mas nem todo grafo é uma arvore 

### Formas de representar um grafo

#### Matriz de adjacência:
- Essa estrutura é frequentemente utilizada para representar grafos não direcionados.
- Considere o seguinte grafo não direcionado:
    ![Alt text](/img/image.png)
- A matriz de adjacência para este grafo seria:
    ![Alt text](matriz_adj.png)

#### lista de adjacência:
- Para cada vértice no grafo, você cria uma lista (ou um arranjo, uma estrutura de dados que pode armazenar múltiplos elementos) que contém todos os vértices adjacentes a ele.
- Maneira mais eficaz para grafos maiores
- Considere o seguinte grafo não direcionado:
    ![Alt text](/img/image.png)
- A lista de adjacência para este grafo seria:

    A: B, C
    B: A, D
    C: A, D
    D: B, C

### Componetes conectados 

- Dois vértices **A** e **B** pertencem ao mesmo componte conectado, quando consigo ir de AB para BA.

#### Componentes Fortemente Conectados

- levo em consideração a direção

#### Componentes Fracamente Conectados

- Não levo em consideração a direção

### Quais os algoritmos mais utilizados em grafos?

- busca em profundidade e busca em largura

### Busca em profundidade 

- Percorre o máximo que puder, até não conseguir desenvolver mais. 
