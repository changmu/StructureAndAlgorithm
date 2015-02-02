////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-19 15:21:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1069
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define maxn 200

int id, cas = 1;
struct Node {
	int x, y, z;
} A[maxn];
int dp[maxn];

bool cmp(Node a, Node b) {
	return a.x > b.x;
}

void addToA(int x, int y, int z) {
	A[id].x = x; A[id].y = y; A[id++].z = z;
	A[id].x = x; A[id].y = z; A[id++].z = y;
	A[id].x = y; A[id].y = z; A[id++].z = x;
	A[id].x = y; A[id].y = x; A[id++].z = z;
	A[id].x = z; A[id].y = x; A[id++].z = y;
	A[id].x = z; A[id].y = y; A[id++].z = x;
}

void solve() {
	int ans, i, j;
	ans = dp[0] = A[0].z;
	for(i = 1; i < id; ++i) {
		dp[i] = A[i].z;
		for(j = i - 1; j >= 0; --j) 
			if(A[i].x < A[j].x && A[i].y < A[j].y)
				dp[i] = max(dp[i], dp[j] + A[i].z);
		ans = max(ans, dp[i]);
	}
	printf("Case %d: maximum height = %d\n", cas++, ans);
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int n, i, x, y, z;
	while(scanf("%d", &n), n) {
		for(i = id = 0; i < n; ++i) {
			scanf("%d%d%d", &x, &y, &z);
			addToA(x, y, z);
		}
		sort(A, A + id, cmp);
		solve();
	}
	return 0;
}
