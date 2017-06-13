#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%lld\n", x)
#define prie(x) printf("%d ", x)
typedef long long int ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
int p[1000100];
int v[1000100];
int n;
int conta[8];
int main()
{
	sc(n);
    int i;
	for(i=1;i<=n;i++) sc(v[i]);
	for(i=1;i<=n;i++) p[i]= (p[i-1]+v[i])%8;
	for(i=1;i<=n;i++) conta[p[i]]++;
	ll r=0;
	for(i=0;i<8;i++){
		r+= (conta[i]*(ll)(conta[i]-1))/2ll;
	}
	r+=conta[0];
	pri(r);
  return 0;
}
