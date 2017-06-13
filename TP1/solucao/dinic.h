#ifndef traulitana 
#define traulitana
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "vector.h"

typedef struct Edge{
    int v;
	 int rev;
    int cap;
}Edge;

typedef struct graph{
    Edge **content;
    int *size;
    int *reserved;
}graph;
//inicializa a estrutura Edge e, atribuindo os respectivos valores
void initEdge(Edge *e, int v, int cap, int rev);

//inicializa o grafo, com n vertices -> alocacao de memoria
void initGraph(int n, graph* g);

//so realloca a lista de adjascencias
void growGraph(graph *g, int u);

//funcao push_back pra lista de adjascencias do grafo
void push_back_ed(graph *g, int u, Edge *a);

// adicionar uma aresta de peso cap u->v
void addEdge(graph *g, int u, int v, int cap);

//construir o grafo de niveis
int buildLevelGraph(graph *g, queue *q, vector *level, int src, int sink);

// achar os gargalos
int blockingFlow(graph *g, vector *level, int u, int sink, int f);

long long maxFlow(graph *g, int src, int sink, int tam);

#endif
