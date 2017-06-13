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
char s[51];
char aux[51];
int main()
{
  scs(s);
  int x=0,i=0;
  for(i=0;s[i];i++){
    if(s[i]=='a') aux[x++]=s[i];
    if(s[i]=='e') aux[x++]=s[i];
    if(s[i]=='i') aux[x++]=s[i];
    if(s[i]=='o') aux[x++]=s[i];
    if(s[i]=='u') aux[x++]=s[i];
  }
  int n=strlen(aux);
  for(i=0;i<n;i++) if(aux[i]!=aux[n-1-i]) {
    puts("N");
    return 0;
  }
  puts("S");
  return 0;
}
