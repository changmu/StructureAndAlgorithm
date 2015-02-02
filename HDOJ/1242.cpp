////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-12 21:32:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1242
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:284KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <queue>
#define maxn 202
using std::priority_queue;

int n, m, ans;
const int mov[][2] = {0, 1, 0, -1, -1, 0, 1, 0};
char map[maxn][maxn];
struct Node{
	int x, y, time;
	friend bool operator<(Node a, Node b){
		return a.time > b.time;
	}
};

bool check(int x, int y){
	return x >= 0 && x < n && y >= 0 
		&& y < m && map[x][y] != '#';
}

bool BFS(int x, int y)
{
	Node now, tmp;
	now.x = x; now.y = y;
	map[x][y] = '#';
	now.time = 0;
	priority_queue<Node> Q;
	Q.push(now);
	while(!Q.empty()){
		now = Q.top(); Q.pop();
		for(int i = 0; i < 4; ++i){
			tmp = now;
			tmp.x += mov[i][0];
			tmp.y += mov[i][1];
			if(check(tmp.x, tmp.y)){
				++tmp.time;
				if(map[tmp.x][tmp.y] == 'x')
					++tmp.time;
				else if(map[tmp.x][tmp.y] == 'r'){
					ans = tmp.time; return true;
				}
				map[tmp.x][tmp.y] = '#';
				Q.push(tmp);
			}
		}
	}
	return false;
}

int main()
{
	int i, j, x, y;
	while(scanf("%d%d", &n, &m) == 2){
		for(i = 0; i < n; ++i){
			getchar();
			for(j = 0; j < m; ++j){
				map[i][j] = getchar();
				if(map[i][j] == 'a'){
					x = i; y = j;
				}
			}
		}
		if(BFS(x, y)) printf("%d\n", ans);
		else printf("Poor ANGEL has to stay in the prison all his life.\n");
	}
	return 0;
}