#include <stdio.h>
#include <string.h>
#define maxn 22
#define UP 0
#define DOWN 1

int vis[maxn], ans[maxn];
__int64 dp[maxn][maxn][2];

void Init(int n)
{
	int i, j, k;
	dp[1][1][UP] = dp[1][1][DOWN] = 1;
	for(i = 2; i <= n; ++i){ //i is the amount of total sticks
		for(j = 1; j <= i; ++j){ //j is the first stick's position
			for(k = j; k < i; ++k) //k is the subSolution of dp array
				dp[i][j][UP] += dp[i-1][k][DOWN];
			for(k = 1; k < j; ++k)
				dp[i][j][DOWN] += dp[i-1][k][UP];
		}
	}
}

void Print(int n, __int64 c)
{
	memset(vis, 0, sizeof(vis));
	int i, j, k, rank;
	__int64 skip = 0, pre = 0;
	for(i = 1; i <= n; ++i){ //i is the position to select now
		rank = 0; //the rank's min stick
		for(j = 1; j <= n; ++j){ //j is the stick to be select		
			pre = skip;	
			if(!vis[j]){
				++rank;
				if(i == 1) skip += dp[n][rank][UP] + dp[n][rank][DOWN];
				else if(j > ans[i-1] && (i == 2 || ans[i-2] > ans[i-1]))
					skip += dp[n-i+1][rank][DOWN];
				else if(j < ans[i-1] && (i == 2 || ans[i-2] < ans[i-1]))
					skip += dp[n-i+1][rank][UP];
				if(skip >= c) break; 
			}
		}
		ans[i] = j;
		vis[j] = 1;
		skip = pre;
	}
	for(i = 1; i <= n; ++i)
		if(i != n) printf("%d ", ans[i]);
		else printf("%d\n", ans[i]);
}

int main()
{
	int t, n;
	__int64 c;
	Init(20);
	scanf("%d", &t);
	while(t--){
		scanf("%d%I64d", &n, &c);
		Print(n, c);
	}
	return 0;
}