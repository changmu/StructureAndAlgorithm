////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-09 17:49:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2717
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:544KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <queue>
#include <string.h>
#define maxn 100002
using std::queue;

struct Node{
	int pos, step;
};
bool vis[maxn];

void move(Node& tmp, int i)
{
	if(i == 0) --tmp.pos;
	else if(i == 1) ++tmp.pos;
	else tmp.pos <<= 1;
}

bool check(int pos)
{
	return pos >= 0 && pos < maxn && !vis[pos];
}

int BFS(int n, int m)
{
	if(n == m) return 0;
	memset(vis, 0, sizeof(vis));
	queue<Node> Q;
	Node now, tmp;
	now.pos = n; now.step = 0;
	Q.push(now);
	vis[n] = 1;
	while(!Q.empty()){
		now = Q.front(); Q.pop();
		for(int i = 0; i < 3; ++i){
			tmp = now;
			move(tmp, i);
			if(check(tmp.pos)){
				++tmp.step;
				if(tmp.pos == m) return tmp.step;
				vis[tmp.pos] = 1;
				Q.push(tmp);
			}
		}
	}
}

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) == 2){
		printf("%d\n", BFS(n, m));
	}
	return 0;
}