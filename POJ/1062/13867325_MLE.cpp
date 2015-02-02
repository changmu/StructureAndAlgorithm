#include <stdio.h>
#include <string.h>

#define inf 0x3f3f3f3f

struct Node {
	int P, L, X; // 价格、主人等级、替代品数
} goods[102];
struct Node2 {
	int T, V; // 编号、价格优惠
} substi[102][102];
int M, N;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int solve(int numOfGoods, int minLevel, int maxLevel) 
{
	if (maxLevel - minLevel > M) return inf;

	int result = goods[numOfGoods].P;
	for (int i = 1; i <= goods[numOfGoods].X; ++i) {
		int tempNumOfGoods = substi[numOfGoods][i].T;
		int minL = min(minLevel, goods[tempNumOfGoods].L);
		int maxL = max(maxLevel, goods[tempNumOfGoods].L);
		result = min(result, solve(tempNumOfGoods, minL, maxL) + substi[numOfGoods][i].V);
	}

	return result;
}

int main() {
	// freopen("data.in", "r", stdin);
	while (scanf("%d%d", &M, &N) == 2) {
		for (int i = 1; i <= N; ++i) {
			scanf("%d%d%d", &goods[i].P, &goods[i].L, &goods[i].X);
			for (int j = 1; j <= goods[i].X; ++j)
				scanf("%d%d", &substi[i][j].T, &substi[i][j].V);
		}

		printf("%d\n", solve(1, goods[1].L, goods[1].L));
	}
	return 0;
}
