#include <stdio.h>
#include <string.h>

#define maxn 110

int N, g_result;
int G[maxn][maxn];

int max(int a, int b) { return a > b ? a : b; }

void solve(const int *numbers)
{
	int result = numbers[1];
	int currentSum = result;
	for (int i = 2; i <= N; ++i) {
		if (currentSum < 0) currentSum = 0;
		currentSum += numbers[i];
		result = max(result, currentSum);
	}

	g_result = max(g_result, result);
}

int main()
{
	// freopen("data.in", "r", stdin);
	while (~scanf("%d", &N)) {
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				scanf("%d", &G[i][j]);
	
		g_result = G[1][1];
		for (int i = 1; i <= N; ++i) {
			solve(G[i]);
			for (int j = i + 1; j <= N; ++j) {
				for (int k = 1; k <= N; ++k)
					G[i][k] += G[j][k];
				solve(G[i]);
			}
		}

		printf("%d\n", g_result);
	}
	return 0;
}
