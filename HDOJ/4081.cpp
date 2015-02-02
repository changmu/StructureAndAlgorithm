////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-08-11 19:08:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4081
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:15496KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#define maxn 1002
#define maxm (maxn * maxn) >> 1
using std::sort;

struct Node{
	int u, v;
	double dist;
} E[maxm]; //存储边
struct Node2{
	int x, y, peo;
} V[maxn]; //存储顶点
int head[maxn], end[maxn]; //存储集合首尾
struct Node3{ 
	int u, next;
} G[maxn]; //链式前向星存集合归属信息
int pre[maxn]; //并查集
double max[maxn][maxn]; //存储最小树上的两点间最长的一条单元路

double maxv(double a, double b){
	return a > b ? a : b;
}

double calDist(int i, int j)
{
	double x = V[i].x - V[j].x;
	double y = V[i].y - V[j].y;
	return sqrt(x * x + y * y);
}

bool cmp(Node a, Node b){
	return a.dist < b.dist;
}

int ufind(int k)
{
	int a = k, b;
	while(pre[k] != -1) k = pre[k];
	while(a != k){
		b = pre[a];
		pre[a] = k;
		a = b;
	}
	return k;
}

double Kruskal(int n, int m)
{
	memset(pre, -1, sizeof(pre));
	int count = n, i, j, k, u, v;
	double len = 0, dist;
	for(i = 0; i < n; ++i){ //初始化每个点的集合只有其本身
		G[i].u = i; G[i].next = -1;
		head[i] = end[i] = i;
	}
	for(i = 0; i < m; ++i){
		u = E[i].u; v = E[i].v;
		dist = E[i].dist;
		u = ufind(u); v = ufind(v);
		if(u != v){
			for(j = head[u]; j != -1; j = G[j].next)
				for(k = head[v]; k != -1; k = G[k].next)
					max[G[j].u][G[k].u] = max[G[k].u][G[j].u] = dist;
			//合并集合
			G[end[v]].next = head[u]; head[u] = head[v];

			pre[v] = u; --count; len += dist;			
			if(1 == count) break; //最小树生成
		}
	}
	return len;
}

int main()
{
	//freopen("stdin.txt", "r", stdin);
	int t, n, i, j, id;
	double minLen, ans;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n; ++i)
			scanf("%d%d%d", &V[i].x, &V[i].y, &V[i].peo);
		for(i = id = 0; i < n; ++i)
			for(j = i + 1; j < n; ++j){
				E[id].u = i; E[id].v = j;
				E[id++].dist = calDist(i, j);
			}
		sort(E, E + id, cmp);
		minLen = Kruskal(n, id);
		ans = 0;
		for(i = 0; i < n; ++i) //枚举所有魔法边
			for(j = i + 1; j < n; ++j){
				ans = maxv(ans, (V[i].peo + V[j].peo) / (minLen - max[i][j]));
			}
		printf("%.2lf\n", ans);
	}
	return 0;
}