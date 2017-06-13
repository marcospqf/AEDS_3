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
int n,m,k;
int g[1010][1010], deg[1010];
int vai[1010];
int cnt=0;
int tira[1010];
int main()
{
    int i;
	while(sc3(n,m,k)==3){
		memset(g,0,sizeof(g));
		memset(deg,0,sizeof(deg));
		memset(tira,0,sizeof(tira));
		cnt=0;
		for(i=0;i<m;i++) {
			int u,v;
			sc2(u,v);
			g[u][v]=g[v][u]=1;
			deg[u]++,deg[v]++;
		}
		for(i=1;i<=n;i++){
			if(deg[i]<k) 
				vai[cnt++]=i;
		}
		while(cnt>0){
			int u=vai[cnt-1];
			tira[u]=1;
			cnt--;
			for(i=1;i<=n;i++){
				if(g[u][i]){
					deg[i]--;
					if(deg[i]==k-1) vai[cnt++]=i;
				}
			}
		}
		int coco=0;
		for(i=1;i<=n;i++) if(!tira[i]) {
			if(coco) printf(" %d", i);
			else printf("%d", i);
			coco=1;
		}
		if(coco==0) pri(0);
		else puts("");
	}
  return 0;
}
