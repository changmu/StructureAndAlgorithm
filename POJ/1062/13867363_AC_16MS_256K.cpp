#include <stdio.h>
#include <string.h>

#define inf 0x3f3f3f3f
#define maxn 110

struct Node {
	int P, L, X; // 价格、主人等级、替代品数
} goods[maxn];
struct Node2 {
	int T, V; // 编号、价格优惠
} substi[maxn][maxn];
int M, N;
bool vis[maxn];

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int solve(int numOfGoods, int minLevel, int maxLevel) 
{
	if (maxLevel - minLevel > M) return inf;
	int tempNumOfGoods, minL, maxL, i;
	int result = goods[numOfGoods].P;

	for (i = 1; i <= goods[numOfGoods].X; ++i) {
		tempNumOfGoods = substi[numOfGoods][i].T;
		if (vis[tempNumOfGoods]) continue;
		vis[tempNumOfGoods] = true;
		minL = min(minLevel, goods[tempNumOfGoods].L);
		maxL = max(maxLevel, goods[tempNumOfGoods].L);
		result = min(result, solve(tempNumOfGoods, minL, maxL) + substi[numOfGoods][i].V);
		vis[tempNumOfGoods] = false;
	}

	return result;
}

int main() {
	// freopen("data.in", "r", stdin);
	int i, j;
	while (scanf("%d%d", &M, &N) == 2) {
		memset(vis, 0, sizeof(vis));
		for (i = 1; i <= N; ++i) {
			scanf("%d%d%d", &goods[i].P, &goods[i].L, &goods[i].X);
			for (j = 1; j <= goods[i].X; ++j)
				scanf("%d%d", &substi[i][j].T, &substi[i][j].V);
		}

		printf("%d\n", solve(1, goods[1].L, goods[1].L));
	}
	return 0;
}
