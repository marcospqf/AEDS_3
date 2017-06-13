#ifndef solver
#define solver

#include "solver.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//recursao para o problema 
void solve(stack *calc, stack *op, long long *input, int idx, int sz_input, long long answer);

//faz a multiplicacao dos 2 elementos do topo da pilha, deletando eles 
//e adicionando o resultado no topo da pilha
void fix_prod(stack *calc);


//faz a soma dos 2 elementos do topo da pilha, deletando eles 
//e adicionando o resultado no topo da pilha
void fix_sum(stack *calc);

//imprime a pilha de operacoes(em char)
void print_carac(stack *op);

#endif
