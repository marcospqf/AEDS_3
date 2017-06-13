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
char g[110][110];
int us[110][110][4];
int m,n;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int dfs(int x,int y, int dir){
	us[x][y][dir]=1;
	if(g[x][y]=='*') {
		return 1;
	}
	int nx=x+dx[dir];
	int ny=y+dy[dir];
	if(nx<0 || ny<0 || nx>=n || ny>=m) return 0;
	
	int ndir=dir;
	if(g[nx][ny]=='>') ndir=0;
	if(g[nx][ny]=='<') ndir=1;
	if(g[nx][ny]=='v') ndir=3;
	if(g[nx][ny]=='^') ndir=2;

	int ret=0;
	if(!us[nx][ny][ndir])
		ret|=dfs(nx,ny,ndir);
	
	if(!us[nx][ny][dir])
		ret|=dfs(nx,ny,dir);
	
	return ret;
}
int main()
{
	sc2(m,n);
	int i,j;
	for(i=0;i<n;i++){
		getchar();
		for(j=0;j<m;j++)
			g[i][j]=getchar();
	}
	int dir=-1;
	if(g[0][0]=='>') dir=0;
	if(g[0][0]=='<') dir=1;
	if(g[0][0]=='v') dir=3;
	if(g[0][0]=='^') dir=2;
	int r=0;
	if(dir>=0) r=dfs(0,0,dir);
	if(r){
		puts("*");
	}
	else puts("!");
  return 0;
}
