////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-22 13:54:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1026
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:384KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <queue>
#include <cstring>
#define maxn 102
using std::priority_queue;

struct Node{
	int x, y, time;
	friend bool operator<(Node a, Node b){
		return a.time > b.time;
	}
};
struct node{
	int x, y, time;
} path[maxn][maxn];
char map[maxn][maxn];
int n, m, mov[][2] = {0, 1, 0, -1, -1, 0, 1, 0};

bool check(int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < m && map[x][y] != 'X';
}

bool BFS(int& times)
{
	Node now, next;
	now.x = now.y = now.time = 0;
	priority_queue<Node> Q;
	Q.push(now);
	while(!Q.empty()){
		now = Q.top(); Q.pop();
		if(now.x == n - 1 && now.y == m - 1){
			times = now.time; return true;
		}
		for(int i = 0; i < 4; ++i){
			next = now;
			next.x += mov[i][0]; next.y += mov[i][1];
			if(!check(next.x, next.y)) continue;
			++next.time;
			path[next.x][next.y].x = now.x;
			path[next.x][next.y].y = now.y;
			path[next.x][next.y].time = 0;
			if(map[next.x][next.y] != '.'){
				next.time += map[next.x][next.y] - '0';
				path[next.x][next.y].time = map[next.x][next.y] - '0';
			}		
			map[next.x][next.y] = 'X'; Q.push(next);
		}
	}
	return false;
}

void printPath(int times, int x, int y)
{
	if(times == 0) return;
	times -= path[x][y].time;
	printPath(times - 1, path[x][y].x, path[x][y].y);
	printf("%ds:(%d,%d)->(%d,%d)\n", 
		times++, path[x][y].x, path[x][y].y, x, y);
	while(path[x][y].time--)
		printf("%ds:FIGHT AT (%d,%d)\n", times++, x, y);	
}

int main()
{
	int times, i;
	while(scanf("%d%d", &n, &m) != EOF){
		for(i = 0; i < n; ++i)
			scanf("%s", map[i]);
		memset(path, 0, sizeof(path));
		if(BFS(times)){
			printf("It takes %d seconds to reach the target position, let me show you the way.\n", times);
			printPath(times, n - 1, m - 1);
		}else puts("God please help our poor hero.");
		puts("FINISH");
	}
	return 0;
}