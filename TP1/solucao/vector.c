#include "vector.h"

/*--------------------VECTOR-------------------*/
void Init_vector(vector *v)
{
    v->size=0;
    v->reserved=2;
    v->content=malloc(sizeof(int)*2);
}

void grow(vector *v)
{
    v->content=realloc(v->content,sizeof(int)*((v->reserved) *2));
    v->reserved*=2;
}

void push_back(vector *v,int val)
{
    if(v->size==v->reserved) grow(v);
    v->content[v->size]=val;
    v->size++;
}
void resize(vector *v, int tam)
{
   v->content=malloc(sizeof(int)*(tam));
	v->size=tam;
	v->reserved=tam;
	for(int i=0;i<tam;i++) v->content[i]=0;
}

void set_free_vector(vector *v)
{
    free(v->content);
    free(v);
}

void poe(vector *v, int x){
	for(int i=0;i<v->size;i++)
		v->content[i]=x;
}

/*-------------------FILA-------------------*/
void Init_queue(queue *q){
	q->size=0;
	q->reserved=2;
	q->content=(int*)malloc(sizeof(int)*2);
	q->frente=0;
}
void grow_queue(queue *q){
	q->content=(int*)realloc(q->content, sizeof(int)*(q->reserved)*2);
	q->reserved*=2;
}
void push_queue(queue *q, int x){
	if(q->size==q->reserved-1) grow_queue(q);
	q->content[q->size]=x;
	q->size++;
}
void pop_queue(queue *q){
	q->frente++;
}

int front_queue(queue *q){
    return q->content[q->frente];
}

int empty_queue(queue *q){
	return (q->frente>=q->size);
}
