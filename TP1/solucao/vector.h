#ifndef stl 
#define stl

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//#define vector(int x) vector.content[x

/*----------------------VECTOR------------------*/
typedef struct vector{
    int *content;
    int size;
    int reserved;
}vector;


//inicializa o vetor
void Init_vector(vector *v);

//aumenta a capacidade do vetor
void grow(vector *v);

void resize(vector *v, int x);
//insere o elemento no fim do vetor
void push_back(vector *v,int val);

//deleta o elemento no fim do vetor
//libera a memoria alocada no vetor
void set_free_vector(vector *v);

void poe(vector *v, int x);



/* ---------------- FILA ---------------------*/


typedef struct queue{
	int *content;
	int size;
	int reserved;
	int frente;
}queue;

//poe x na fila
void push_queue(queue *q, int x);

//tira o primeiro da fila
void pop_queue(queue *q);

//retorna o primeiro da fila
int front_queue(queue *q);

//tamanho da fila
int size_queue(queue *q);

// fila esta vazia?!
int empty_queue(queue *q);

// inicializa a fila
void Init_queue(queue *q);
#endif
