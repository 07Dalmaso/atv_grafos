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

- Matriz de adjacência 
- lista de adjacência 

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
