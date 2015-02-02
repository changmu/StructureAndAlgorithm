////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-19 13:37:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1068
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 1010

int n, A[maxn], B[maxn];
bool vis[maxn];
int head[maxn], id;
struct Node {
	int v, next;
} E[maxn * maxn];

void addEdge(int u, int v) {
	E[id].v = v; E[id].next = head[u];
	head[u] = id++;
}

void getMap() {
	int i, u, k, v; id = 0;
	memset(head, -1, sizeof(int) * n);
	memset(B, -1, sizeof(int) * n);
	for(u = 0; u < n; ++u) {
		scanf("%*d: (%d)", &k);
		while(k--) {
			scanf("%d", &v);
			addEdge(u, v);
		}
	}
}

int findPath(int x) {
	int i, v;
	for(i = head[x]; i != -1; i = E[i].next) {
		if(!vis[v = E[i].v]) {
			vis[v] = 1;
			if(B[v] == -1 || findPath(B[v])) {
				B[v] = x; return 1;
			}
		}
	}
	return 0;
}

int MaxMatch() {
	int ans = 0, i;
	for(i = 0; i < n; ++i) {
		memset(vis, 0, sizeof(bool) * n);
		ans += findPath(i);
	}
	return ans;
}

void solve() {
	printf("%d\n", n - (MaxMatch() >> 1));
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	while(scanf("%d", &n) == 1) {
		getMap();
		solve();
	}
	return 0;
}