////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-06-18 10:01:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1253
////Problem Title: 
////Run result: Accept
////Run time:500MS
////Run memory:936KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <queue>
using std::queue;
int a, b, c, times;
int map[52][52][52];
bool vis[52][52][52];
const int mov[][3] = {
0, 0, 1, 0, 1, 0,
1, 0, 0, 0, 0, -1,
0, -1, 0, -1, 0, 0
};
struct Node{
	int x, y, z, steps;
};
queue<Node> Q;

bool check(Node k){
	if(k.x < 0 || k.y < 0 || k.z < 0 ||
		k.x >= a || k.y >= b || k.z >= c) return 0;
	if(vis[k.x][k.y][k.z] || map[k.x][k.y][k.z]) 
		return 0;
	return 1;
}

int BFS(){
	while(!Q.empty()) Q.pop();
	Node temp, now = {0};
	vis[0][0][0] = 1;
	if(a == b && a == c && a == 1) return 0;
	Q.push(now);
	while(!Q.empty()){
		now = Q.front();
		Q.pop();
		
		if(now.steps == times) continue;
		
		for(int i = 0; i < 6; ++i){
			temp = now; ++temp.steps;
			temp.x += mov[i][0];
			temp.y += mov[i][1];
			temp.z += mov[i][2];
			if(check(temp)){
				if(temp.x == a-1 && temp.y == b-1 && temp.z == c-1)
					return temp.steps;
				vis[temp.x][temp.y][temp.z] = 1;
				Q.push(temp);				
			}
		}
	}
	return -1;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &a, &b, &c, &times);
		for(int i = 0; i < a; ++i)
			for(int j = 0; j < b; ++j)
				for(int k = 0; k < c; ++k){
					scanf("%d", &map[i][j][k]);
					vis[i][j][k] = 0;
				}
		if(a + b + c - 3 > times || 
			map[a-1][b-1][c-1] == 1) printf("-1\n"); //cut
		else printf("%d\n", BFS());
	}
	return 0;
}