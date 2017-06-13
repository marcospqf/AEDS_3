#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "dinic.h"

void initEdge(Edge *e,int v, int cap , int rev){
    e->v=v;
    e->cap=cap;
    e->rev=rev;
}
void initGraph(int n,graph* g){
    g->content=(Edge**)malloc(n*sizeof(Edge*));
    g->size= (int*)malloc(n*sizeof(int));
    g->reserved= (int*)malloc(n*sizeof(int));
	 for(int i=0;i<n;i++) g->content[i]=(Edge*)malloc(2*sizeof(Edge));
    for(int i=0;i<n;i++) g->size[i]=0;
    for(int i=0;i<n;i++) g->reserved[i]=2;
}

void growGraph(graph *g, int u)
{
	 g->content[u]= (Edge*)realloc(g->content[u],sizeof(Edge)*( (g->reserved[u])*2) );
	 g->reserved[u]*=2;
}

void push_back_ed(graph *g, int u, Edge *a){
    if(g->size[u] == g->reserved[u]) growGraph(g,u); 
    g->content[u][g->size[u]]=*a;
    g->size[u]++;
}

void addEdge(graph *g, int u, int v, int cap){
    if(u==v) return;
    Edge e;
    initEdge(&e,v,cap,g->size[v]);
	 push_back_ed(g,u,&e);
    Edge r;
    initEdge(&r,u,0,g->size[u]);
	 push_back_ed(g,v,&r);
}

int buildLevelGraph(graph *g, queue *q, vector *level, int src, int sink){
    poe(level,-1);
    while(!empty_queue(q) ) pop_queue(q);
	 level->content[src]=0;
    push_queue(q, src);
    while(!empty_queue(q)){
        int u= front_queue(q);
       	pop_queue(q);
        for(int i=0;i<g->size[u];i++){
            Edge *e= &(g->content[u][i]);
            if(!e->cap || level->content[e->v]!=-1) continue;
            level->content[e->v] = level->content[u] +1;
            if(e->v ==sink) return 1;
            push_queue(q,e->v);
        }
    }
    return 0;
}

int blockingFlow(graph *g, vector *level, int u, int sink, int f){
    if(u==sink || !f) return f;
    int fu=f;
    for(int i=0;i<g->size[u];i++){
        Edge *e= &(g->content[u][i]);
        if(!e->cap || level->content[e->v]!= level->content[u]+1) continue;
        int mincap = blockingFlow(g,level,e->v, sink, (fu < e->cap) ? fu : e->cap);
        if(mincap){
            g->content[e->v][e->rev].cap +=mincap;
            e->cap-= mincap;
            fu-=mincap;
        }
    }
    if(f==fu) level->content[u]=-1;
    return f-fu;
}


long long maxFlow(graph *g, int src, int sink, int tam){
    long long flow=0;
    vector level;
	 resize(&level, tam);
	 poe(&level, -1);
	 queue q;
	 Init_queue(&q);
    while(buildLevelGraph(g, &q,&level,src, sink)){
    	flow+=blockingFlow(g,&level,src, sink, 0x3f3f3f3f);
	 }
	 free(level.content);
	 free(q.content);
    return flow;
}
