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
//int dy[]={1,0,-1,-1,0,1,1,1};
//int dx[]={0,-1,0,1,1,0,0,-1};
//int qnt[]={0,0,0,0,0,0,0,-1};

int dx[]={0,-1,-1,0,1,1};
int dy[]={1,1,0,-1,-1,0};
int qnt[]={0,-1,0,0,0,0};
int main()
{
	int n=0;
	while(sc(n)==1){
		n--;
		int x=0,y=0;
		int j=0;
		int cnt=1;
		while(n>0){
			int k;
			for(k=0;k<cnt+qnt[j];k++) {
				n--;
				x+=dx[j];
				y+=dy[j];
				if(n==0) break;
			}
			j++;
			if(j==6){
				cnt++;
				j=0;
			}
		}
		prie(x);
		pri(y);
	}

  return 0;
}
