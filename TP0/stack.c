#include "stack.h"


void Init_vector(vector *v)
{
  v->size=0;
  v->reserved=2;
  v->content=malloc(sizeof(long long)*2);
}

void grow(vector *v)
{
  v->content=realloc(v->content,sizeof(long long)*((v->reserved) *2));
  v->reserved*=2;
}

void push_back(vector *v,long long val)
{
  if(v->size==v->reserved) grow(v);
  v->content[v->size]=val;
  v->size++;
}

void pop_back(vector *v)
{
  if(v->size==0) return;
  v->size--;
}

int empty(vector *v)
{
  return (v->size == 0);
}

int size(vector *v)
{
  return v->size;
}

long long access(vector *v, int idx)
{
  return v->content[idx];
}

void set_free_vector(vector *v)
{
  free(v->content);
  free(v);
}


void Init_stack(stack *s)
{
  s->v=malloc(sizeof(vector));
  Init_vector(s->v);
}

void push(stack *s, long long val)
{
  push_back(s->v,val);
}

void pop(stack *s)
{
  pop_back(s->v);
}

long long top(stack *s)
{
//  assert(size(s->v)>0);
  
  return access(s->v,size(s->v)-1);
}

int is_empty(stack *s)
{
  return empty(s->v);
}
void LIBERA_GERAL(stack *s)
{
  set_free_vector(s->v);
}

void print_stack(stack *s){
  int tam=size(s->v);
  int i;
  for(i=0;i<tam;i++){
    printf("%c", (char)access(s->v,i));
  }
  printf("\n");
}
