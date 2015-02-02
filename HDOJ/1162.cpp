////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-29 15:55:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1162
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:296KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#include <string.h>
#define maxn 102

double _x[maxn], _y[maxn];
double map[maxn][maxn];
bool vis[maxn];

double cal(int i, int j)
{
	double x = _x[i] - _x[j];
	double y = _y[i] - _y[j];
	return sqrt(x * x + y * y);
}

void Prim(int n)
{
	int i, j, count = 0, u;
	double len = 0, tmp;
	vis[0] = 1;
	while(count < n - 1){
		for(i = 0, tmp = -1; i < n; ++i){
			if(!vis[i]) continue;
			for(j = 0; j < n; ++j)
				if(!vis[j] && (map[i][j] < tmp || tmp < 0)){
					tmp = map[i][j]; u = j;
				}
		}
		if(tmp >= 0){
			++count; vis[u] = 1;
			len += tmp;
		}
	}
	printf("%.2lf\n", len);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, i, j;
	double len;
	while(scanf("%d", &n) != EOF){
		memset(vis, 0, sizeof(vis));
		for(i = 0; i < n; ++i){
			scanf("%lf%lf", _x + i, _y + i);
			for(j = 0; j < i; ++j){
				len = cal(i, j);
				map[i][j] = map[j][i] = len;
			}
		}
		Prim(n);
	}
	return 0;
}
