#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "dinic.h"
#include "solver.h"
int main()
{
	int v,e,f,c;
	int *franquias;
	int *clientes;
	graph g;
	scanf("%d %d %d %d", &v , &e , &f, &c);
	franquias=(int*) malloc(f*sizeof(int));
	clientes=(int*) malloc(c*sizeof(int));
	initGraph(v+10,&g);
	for(int i=0;i<e;i++){
		int u,v,w;
		scanf("%d %d %d", &u ,&v, &w);
		addEdge(&g,u,v,w);
	}
	for(int i=0;i<f;i++) scanf("%d", &franquias[i]);
	for(int i=0;i<c;i++) scanf("%d", &clientes[i]);
	solve(franquias, clientes, &g,f,c, v);

	for(int i=0;i<v+10;i++) free(g.content[i]);
	free(g.reserved);
	free(g.size);
	free(g.content);
	free(franquias);
	free(clientes);
  return 0;
}
