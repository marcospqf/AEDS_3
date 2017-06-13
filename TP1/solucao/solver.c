#include "solver.h"

void solve(int *franquias, int *clientes, graph *g, int f, int c, int n)
{
	int src=n+1;
	int sink=n+2;
	for(int i=0;i<f;i++) addEdge(g,src, franquias[i], 0x3f3f3f3f);
	for(int i=0;i<c;i++) addEdge(g,clientes[i],sink, 0x3f3f3f3f);
	long long r=maxFlow(g,src,sink,n+10);
	printf("%lld\n", r);
}
