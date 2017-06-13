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
int cara[510][2];
int sz[510];
int n,c;
int qts[110];
int lista[110][510];
int us[510],deg[110];
int forma_ciclo(int u, int k, int root){
	us[u]=1;
	int nextk;
	int ret=0;
	if(cara[u][0]==k) nextk=cara[u][1];
	else nextk=cara[u][0];
	if(nextk==root) return 1;
	int i;
	for(i=0;i<qts[nextk];i++) {
		if(!us[lista[nextk][i]]) ret|=forma_ciclo(lista[nextk][i],nextk,root);
	}
	return ret;
}
void dfs(int u){
	us[u]=1;
	int i;
	for(i=0;i<qts[u];i++){
		int v=lista[u][i];
		if(!us[cara[v][0]]) dfs(cara[v][0]);
		if(!us[cara[v][1]]) dfs(cara[v][1]);
	}
}
void solve()
{
	memset(deg,0,sizeof(deg));
	int i;
	for(i=0;i<n;i++){
		if(sz[i]==2){
			deg[cara[i][0]]++;
			deg[cara[i][1]]++;
		}
	}
	int impar=0;
	for(i=1;i<=c;i++){
		if(deg[i]%2) impar++;
	}
	if(impar>2 || impar&1)
	{
		pri(-1);
		return;
	}
	else {
		memset(us,0,sizeof(us));
		int i;
		for(i=1;i<=c;i++) if(qts[i]>0) {
			dfs(i);
			break;
		}
		for(i=1;i<=c;i++) if(!us[i] && qts[i]>0){
			pri(-1);
			return;
		}
	}
	if(impar==0){
		pri(0);
		return;
	}
	else{
		int r=INF;
		int i,j;
		for(i=1;i<=c;i++){
			if(deg[i]%2){
				if(deg[i]==1 && qts[i]>1){
					for(j=0;j<qts[i];j++) if(sz[lista[i][j]]==1) r=(r>lista[i][j]) ? lista[i][j] : r;
				}
				else if(deg[i]==1){
					for(j=0;j<qts[i];j++) r=(r>lista[i][j]) ?  lista[i][j] : r;
				}
				else{
					for(j=0;j<qts[i];j++) {
						memset(us,0,sizeof(us));
						if( forma_ciclo(lista[i][j],i,i) ) r=(r>lista[i][j]) ?  lista[i][j] : r;
					}
				}
			}
		}
		pri(r);
	}
}
int main()
{
	while(1){
		sc2(n,c);
		if(n+c==0) break;
		memset(cara,-1,sizeof(cara));
		memset(sz,0,sizeof(sz));
		memset(qts,0,sizeof(qts));
		memset(lista,0,sizeof(lista));
		int i,j;
		for(i=1;i<=c;i++){
			int k;
			sc(k);
			qts[i]=k;
			for(j=0;j<k;j++){
				int u;
				sc(u);
				cara[u][sz[u]]=i;
				sz[u]++;
				lista[i][j]=u;
			}
		}
		for(i=0;i<n;i++) if(sz[i]==1) cara[i][1]=cara[i][0];
		solve();
	}
	return 0;
}

