////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-06 18:09:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1495
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1280KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <queue>
#define maxn 102
using std::queue;

int s, n, m;
bool vis[maxn][maxn][maxn];
struct Node{
	int a[3], step;
} cup;

bool del(Node& tmp, int from, int to)
{
	if(!tmp.a[from] || tmp.a[to] == cup.a[to]) return 0;
	int t = tmp.a[from] + tmp.a[to];
	if(t >= cup.a[to]){
		tmp.a[to] = cup.a[to];
		tmp.a[from] = t - cup.a[to];
	}else{
		tmp.a[to] = t;
		tmp.a[from] = 0;
	}
	if(vis[tmp.a[0]][tmp.a[1]][tmp.a[2]]) return 0;
	return vis[tmp.a[0]][tmp.a[1]][tmp.a[2]] = 1;
}

void BFS()
{
	queue<Node> Q;
	int i, j;
	Node now, tmp;
	now.a[0] = s << 1; now.a[1] = now.a[2] = 0;
	now.step = 0;
	Q.push(now);
	while(!Q.empty()){
		now = Q.front(); Q.pop();
		for(i = 0; i < 3; ++i){
			for(j = 0; j < 3; ++j){
				if(i != j){
					tmp = now;
					++tmp.step;
					if(del(tmp, i, j)){
						if(tmp.a[0] == s && tmp.a[1] == s || tmp.a[0] == s && tmp.a[2] == s || tmp.a[1] == s && tmp.a[2] == s){
							printf("%d\n", tmp.step); return;
						}
						Q.push(tmp);
					}
				}
			}
		}
	}
	printf("NO\n");
}

int main()
{
	while(scanf("%d%d%d", &s, &n, &m), s||n||m){		
		if(s & 1){
			printf("NO\n"); continue;
		}
		memset(vis, 0, sizeof(vis));
		cup.a[0] = s; cup.a[1] = n, cup.a[2] = m;
		s >>= 1; BFS();
	}
	return 0;
}