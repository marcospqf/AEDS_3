#ifndef xablau
#define xablau
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct vector{
	long long *content;
	int size;
	int reserved;
}vector;

typedef struct stack{
	vector *v;
}stack;

//inicializa o vetor
void Init_vector(vector *v);

//aumenta a capacidade do vetor
void grow(vector *v);

//insere o elemento no fim do vetor
void push_back(vector *v,long long val);

//deleta o elemento no fim do vetor
void pop_back(vector *v);

//1- se o vetor esta vazio 0- se o vetor nao esta vazio
int empty(vector *v);

//retorna o tamanho do vetor
int size(vector *v);

// acessa a posicao idx do vetor
long long access(vector *v, int idx);

//libera a memoria alocada no vetor
void set_free_vector(vector *v);

// inicia a pilha
void Init_stack(stack *s);

// adiciona um elemento na pilha ( no topo)
void push(stack *s, long long val);

// deleta o elemento do topo da tilha
void pop(stack *s);

//retorna o elemento do topo da pilha
long long top(stack *s);

// retorna se a pilha esta vazia (1- pilha vazia) (0- pilha nao vazia);
int is_empty(stack *s);

// libera a memoria alocada para a pilha
void LIBERA_GERAL(stack *s);

//imprime o conteudo (em char) da pilha;
void print_stack(stack *s);


#endif
