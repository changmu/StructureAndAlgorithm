////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-08-04 09:25:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1728
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:292KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <queue>
#define maxn 102
using std::queue;

char map[maxn][maxn];
int steps, m, n, step[maxn][maxn];
int mov[][2] = {1, 0, -1, 0, 0, 1, 0, -1};
struct Node{
	int x, y;
	Node operator+(int i){
		Node t;
		t.x = x + mov[i][0];
		t.y = y + mov[i][1];
		return t;
	}
};

bool check(int x, int y)
{
	return x < m && x >= 0 && y < n && y >= 0 
		&& map[x][y] != '*';
}

bool BFS(int x, int y)
{
	if(map[x][y] == 'T') return true;
	memset(step, -1, sizeof(step));
	Node now, t;
	int i;
	now.x = x; now.y = y;
	queue<Node> Q;
	Q.push(now);
	while(!Q.empty()){
		now = Q.front(); Q.pop();
		for(i = 0; i < 4; ++i){
			t = now + i;
			while(check(t.x, t.y)){
				//保证不重复入队，可能出现路线交叉的情况
				if(step[t.x][t.y] == -1){
					step[t.x][t.y] = step[now.x][now.y] + 1;
					if(map[t.x][t.y] == 'T'){
						if(step[t.x][t.y] <= steps) return 1;
						return 0;
					}
					Q.push(t);
				}
				t = t + i;
			}
		}
	}
	return false;
}

int main()
{
	int t, x1, y1, x2, y2, i;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &m, &n);
		for(i = 0; i < m; ++i)
			scanf("%s", map[i]);
		scanf("%d%d%d%d%d", &steps, &y1, &x1, &y2, &x2);
		--x1; --y1; --x2; --y2;
		map[x2][y2] = 'T';
		if(BFS(x1, y1)) puts("yes");
		else puts("no");
	}
	return 0;
}
