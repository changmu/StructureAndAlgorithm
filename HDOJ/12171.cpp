////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-12 16:09:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1217
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:296KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#define maxn 36
using namespace std;

double rate[maxn][maxn], dist[maxn];
bool vis[maxn];

void SPFA(int s, int n)
{
	int i, j, now, tmp;
	for(i = 1; i <= n; ++i){
		vis[i] = 0; dist[i] = 0.0;
	}
	queue<int> Q;
	dist[s] = 1.0; vis[s] = 1;
	Q.push(s);
	while(!Q.empty()){
		now = Q.front(); Q.pop();
		vis[now] = 0;
		for(i = 1; i <= n; ++i){
			if(dist[i] < dist[now] * rate[now][i]){
				if(!vis[i]) Q.push(i); vis[i] = 1;
				dist[i] = dist[now] * rate[now][i];
				if(dist[s] > 1) return;
			}
		}
	}
}

int main()
{
	int n, i, m, cas = 1;
	char buf[50], buf2[50];
	double val;
	map<string, int> mp;
	while(scanf("%d", &n), n){
		mp.clear();
		memset(rate, 0, sizeof(rate));
		for(i = 1; i <= n; ++i){
			scanf("%s", buf);
			mp[buf] = i;
		}
		scanf("%d", &m);
		for(i = 0; i < m; ++i){
			scanf("%s%lf%s", buf, &val, buf2);
			rate[mp[buf]][mp[buf2]] = val;
		}
		SPFA(1, n);
		printf("Case %d: %s\n", cas++, dist[1] > 1 ? "Yes" : "No");
	}
	return 0;
}
