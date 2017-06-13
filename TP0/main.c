#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "solver.h"
void arrumaentrada(char *s, int *sz, long long *input){

  int n=strlen(s);
  long long prox=0;
  int i;
  for(i=0;i<n;i++){
    if(s[i]=='?'){
      prox=-1;
    }
    else if(s[i]>='0' && s[i]<='9'){
      prox*=10ll;
      prox+=(s[i]-'0');
    }
    else{
      if(prox!=0)
        input[(*sz)++]=prox;
      prox=0;
    }
  }
  if(prox!=0)
    input[(*sz)++]=prox;
}
int main()
{
  char *pilha;
  long long input[210],answer;
  int tam=210;
  memset(input,0,sizeof(input));

  pilha=(char *) malloc(tam+1);
  
  fgets(pilha, tam,stdin);
  
  scanf("%lld",&answer);

  int n=0;
  
  arrumaentrada(pilha,&n,input);
  
  //for(int i=0;i<n;i++) printf("%lld ", input[i]);
 // puts("");
  
  stack op, calc;
  Init_stack(&op);
  Init_stack(&calc);

  int pode=1;
  int r=0;
  for(int i=0;i<n;i++){
    if(r<1 && i>1) pode=0;
    r+= (input[i]>=0) ? 1 : -1;
    if(r<1 && i>1) pode=0;
  }
  //printf("%d\n",r); 
  if(pode && r==1)
    solve(&calc, &op, input,0,n,answer);

  // liberar a memoria alocada
  LIBERA_GERAL(&calc);
  LIBERA_GERAL(&op);
  
  free(pilha);
  return 0;
}
