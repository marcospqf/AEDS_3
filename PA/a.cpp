#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define db(x) cerr << #x << " == " << x << endl
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;
typedef vector< vii> vvii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
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
	for(int i=0;i<qts[nextk];i++) {
		if(!us[lista[nextk][i]]) ret|=forma_ciclo(lista[nextk][i],nextk,root);
	}
	return ret;
}
void dfs(int u){
	us[u]=1;
	for(int i=0;i<qts[u];i++){
		int v=lista[u][i];
		if(!us[cara[v][0]]) dfs(cara[v][0]);
		if(!us[cara[v][1]]) dfs(cara[v][1]);
	}
}
void solve()
{
	memset(deg,0,sizeof(deg));
	for(int i=0;i<n;i++){
		if(sz[i]==2){
			deg[cara[i][0]]++;
			deg[cara[i][1]]++;
		}
	}
	int impar=0;
	for(int i=1;i<=c;i++){
		if(deg[i]%2) impar++;
	}
	if(impar>2 or impar&1)
	{
		pri(-1);
		return;
	}
	else {
		memset(us,0,sizeof(us));
		for(int i=1;i<=c;i++) if(qts[i]>0) {
			dfs(i);
			break;
		}
		for(int i=1;i<=c;i++) if(!us[i] and qts[i]>0){
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
		for(int i=1;i<=c;i++){
			if(deg[i]%2){
				if(deg[i]==1 and qts[i]>1){
					for(int j=0;j<qts[i];j++) if(sz[lista[i][j]]==1) r=min(r,lista[i][j]);
				}
				else if(deg[i]==1){
					for(int j=0;j<qts[i];j++) r=min(r,lista[i][j]);
				}
				else{
					for(int j=0;j<qts[i];j++) {
						memset(us,0,sizeof(us));
						if( forma_ciclo(lista[i][j],i,i) ) r=min(r,lista[i][j]);
					}
				}
			}
		}
		pri(r);
	}
}
int main()
{
	while(true){
		sc2(n,c);
		if(n+c==0) break;
		memset(cara,-1,sizeof(cara));
		memset(sz,0,sizeof(sz));
		memset(qts,0,sizeof(qts));
		memset(lista,0,sizeof(lista));
		for(int i=1;i<=c;i++){
			int k;
			sc(k);
			qts[i]=k;
			for(int j=0;j<k;j++){
				int u;
				sc(u);
				cara[u][sz[u]]=i;
				sz[u]++;
				lista[i][j]=u;
			}
		}
		for(int i=0;i<n;i++) if(sz[i]==1) cara[i][1]=cara[i][0];
		solve();
	}
	return 0;
}
