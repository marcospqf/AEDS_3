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
char s[10010],v[10010],cons[10010];
int szv,szc;
int evog(char c){
  if(c=='a' || c =='e' || c =='i' || c =='o' || c =='u') return 1;
  return 0;
} 
void solve()
{
  int q,i,j,n;
  szv=0,szc=0;
  scs(s);
  sc(q);
  n=strlen(s);

  for(i=0;i<n;i++){
    if(evog(s[i])) v[szv++]=s[i];
    else cons[szc++]=s[i];
  }
  
  ll c=0;
  ll vog=0;
  
  for(i=0;i<q;i++){
    int op,x;
    sc(op);
    if(op==0){
      sc(x);
      vog+=x;
    }
    else if(op==1){
      sc(x);
      c+=x;
    }
    else{
      int va=0,ca=0;
      for(j=0;j<n;j++){
        if(evog(s[j])){
          printf("%c",v[(  (va-vog)%szv+szv)%szv ]);
          va++;
        }
        else{
          printf("%c",cons[ ( (ca-c)%szc+szc)%szc ]);
          ca++;
        }
      }
      printf("\n");
    }
  }
}
int main()
{
  int t,i;
  sc(t);
  for(i=1;i<=t;i++){
    printf("Caso #%d:\n",i);
    solve();
  }
  return 0;
}
