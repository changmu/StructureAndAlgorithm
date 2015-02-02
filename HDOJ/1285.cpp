////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-31 21:13:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1285
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:484KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#define maxn 502
using namespace std;

bool map[maxn][maxn];
int indegree[maxn], ans[maxn], queue[maxn];

void topSort(int n)
{
	int id = 0, u;
	priority_queue<int, vector<int>, greater<int> > Q;
	for(int i = 1; i <= n; ++i)
		if(!indegree[i]) Q.push(i);
	while(!Q.empty()){
		u = ans[id++] = Q.top(); Q.pop();
		for(int i = 1; i <= n; ++i){
			if(map[u][i] && !--indegree[i])
				Q.push(i);
		}
	}
}

int main()
{
	int n, m, a, b, i;
	while(scanf("%d%d", &n, &m) != EOF){
		memset(map, 0, sizeof(map));
		while(m--){
			scanf("%d%d", &a, &b);
			if(!map[a][b]){
				++indegree[b];
				map[a][b] = 1;
			}
		}
		topSort(n);
		for(i = 0; i < n; ++i)
			if(i != n - 1) printf("%d ", ans[i]);
			else printf("%d\n", ans[i]);
	}
	return 0;
}
