#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
typedef long long int ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MOD = 1e9 + 9;
char* s[101000];
int compare(const void *p1, const void *p2){
  return strcmp(* (char * const *) p1, * (char * const *) p2);
}
int epref(int x, int y){
  int n=strlen(s[x]);
  int m=strlen(s[y]);
  int i;
  if(n>m) return 0;
  for(i=0;i<n;i++) if(s[x][i]!=s[y][i]) return 0;
  return 1;
}
void solve(int n)
{
  int i=0;
  for(i=0;i<n;i++){
    s[i]=malloc(110*sizeof(char));
    scs(s[i]);
  }
  qsort(&s,n,sizeof(char*),compare); 
  for(i=0;i<n-1;i++){
     if(epref(i,i+1)){
       puts("Conjunto Ruim");
       return;
     }
  }
  puts("Conjunto Bom");
}
int main()
{
  while(1){
    int n;
    sc(n);
    if(n==0) break;
    solve(n);
  }
  return 0;
}
