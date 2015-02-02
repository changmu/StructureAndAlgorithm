////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-27 20:26:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2063
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 510
#define maxm 1010

int k, m, n;
int B[maxn];
bool vis[maxn];
int head[maxn], id;
struct Node {
	int v, next;
} E[maxm];

void addEdge(int u, int v) {
	E[id].v = v; E[id].next = head[u];
	head[u] = id++;
}

void getMap() {
	int u, v; id = 0;
	memset(head, -1, sizeof(int) * (m + 1));
	while(k--) {
		scanf("%d%d", &u, &v);
		addEdge(u, v);
	}
}

int findPath(int k) {
	int i, v;
	for(i = head[k]; i != -1; i = E[i].next) {
		if(!vis[v=E[i].v]) {
			vis[v] = 1;
			if(B[v] == -1 || findPath(B[v])) {
				B[v] = k; return 1;
			}
		}
	}
	return 0;
}

int MaxMatch() {
	memset(B, -1, sizeof(int) * (n + 1));
	int i, ans = 0;
	for(i = 1; i <= m; ++i) {
		memset(vis, 0, sizeof(vis));
		ans += findPath(i);
	}
	return ans;
}

void solve() {
	printf("%d\n", MaxMatch());
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	while(scanf("%d%d%d", &k, &m, &n) == 3) {
		getMap();
		solve();
	}
	return 0;
}