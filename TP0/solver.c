#include "solver.h"
void solve(stack *calc, stack *op, long long *input, int idx, int sz_input, long long answer){
  //CASO BASE , SE O TOPO DA PILHA = RESPOSTA, SIGNIFICA QUE AS OPERACOES SIMULADAS
  //SAO UMA SOLUCAO PARA O PROBLEMA 
    if(idx==sz_input && top(calc)==answer) print_carac(op);
    if(idx==sz_input){
      return;
    }
    
  //SE O ELEMENTO[IDX] FOR UM INTEIRO, COLOCA-LO NA PILHA  
    if(input[idx]>0){
      push(calc,input[idx]);
      solve(calc, op , input, idx+1, sz_input, answer);
      
      pop(calc);
      
    }    
    else{
    // BACKTRACKING SIMPLES
    // ADICIONAR OS OPERADORES E FAZER AS OPERACOES
      push(op, (long long)'+');
      long long last1=top(calc);
      pop(calc);
      long long last2=top(calc);
      push(calc,last1);

      fix_sum(calc);
      
      // PODA DA RECURSAO
      if(last1+last2<=answer) 
        solve(calc,op,input,idx+1,sz_input,answer);
     
      //VOLTAR AO QUE ERA ANTES
      pop(op);
      pop(calc);
      
      push(calc,last2);
      push(calc,last1);
       
    
      //MESMO PROCEDIMENTO FEITO ACIMA
      push(op, (long long)'*');

      fix_prod(calc);
     
      //PODA DA RECURSAO!!
      if(last1*last2<=answer)
        solve(calc,op,input,idx+1,sz_input,answer);
      
      pop(op);
      pop(calc);
      push(calc,last2);
      push(calc,last1);
    }

}


void fix_prod(stack *calc){
  long long x1=top(calc);
  pop(calc);
  long long x2=top(calc);
  pop(calc);
  push(calc,x1*x2);
}

void fix_sum(stack *calc){

  long long x1=top(calc);
  pop(calc);
  long long x2=top(calc);
  pop(calc);
  push(calc,x1+x2);
}

void print_carac(stack *op){
  print_stack(op);
}
