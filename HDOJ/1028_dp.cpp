/*
 * HDU1028 整数拆分
 * */
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 125;
int dp[maxn][maxn], N;

/* 数n拆分后最大数不大于m时的方案数 */
int DFS(int n, int m)
{
    if (dp[n][m]) return dp[n][m];
    if (n < 1 || m < 1) return 0;

    if (n < m) m = n;

    return dp[n][m] = DFS(n, m - 1) + (n == m ? 1 : DFS(n - m, m));
}

int main()
{
    dp[1][1] = 1;
    while (~scanf("%d", &N)) {
        printf("%d\n", DFS(N, N));
    }
    return 0;
}
