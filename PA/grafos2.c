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
const int MOD = 1e9 + 9;
int p[210];
void init()
{
	int i;
	for(i=0;i<210;i++) p[i]=i;
}
int findSet(int i)
{
	if(p[i]==i) return i;
	return p[i]=findSet(p[i]);
}
int sameSet(int i, int j)
{
	return (findSet(i) == findSet(j));
}
void unionSet(int i, int j)
{
	int x = findSet(i), y=findSet(j);
	if(x!=y)
		p[x]=y;
}

typedef struct node{
	int u,v, w,idx;
}node;
node ed[210];
int r, c;
int compare( const void *p1, const void *p2){
	node *x= (node*)p1;
	node *y= (node*)p2;
	return (x->w > y->w)? 1 : -1;
}
int main()
{
	sc2(r,c);
	int i;
	for(i=0;i<c;i++){
		sc3(ed[i].u,ed[i].v,ed[i].w);
		ed[i].idx=i;
	}
	init();
	qsort(ed,c,sizeof(node),compare);
	ll tot=0;
	ll evitou=0;
	for(i=0;i<c;i++){
	//	prie(ed[i].w);
		tot+=ed[i].w;
		if(!sameSet(ed[i].u, ed[i].v)){
			evitou+=ed[i].w;
			unionSet(ed[i].u,ed[i].v);
		}
	}

	pri(evitou);
//	pri(tot);
  return 0;
}
