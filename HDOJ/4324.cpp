////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-02 11:13:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4324
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:4144KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 2002

bool map[maxn][maxn];
char buf[maxn];
int indegree[maxn], queue[maxn];

void addEdge(int n)
{
	int i, j;
	for(i = 0; i < n; ++i){
		scanf("%s", buf);
		for(j = 0; j < n; ++j)
			if(buf[j] == '0') map[i][j] = 0;
			else{
				map[i][j] = 1;
				++indegree[j];
			}
	}
}

bool topoSort(int n)
{
	int i, u, front = 0, back = 0;
	for(i = 0; i < n; ++i)
		if(!indegree[i]) queue[back++] = i;
	while(front != back){
		u = queue[front++];
		for(i = 0; i < n; ++i){
			if(map[u][i] && !--indegree[i])
				queue[back++] = i;
		}
	}
	return back == n;
}

int main()
{
	int t, n, cas = 1;
	scanf("%d", &t);
	while(t--){
		memset(indegree, 0, sizeof(indegree));
		scanf("%d", &n); addEdge(n);
		printf("Case #%d: ", cas++);
		if(!topoSort(n)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}