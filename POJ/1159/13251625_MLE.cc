#include <stdio.h>
#include <string.h>
#define maxn 5002

char str1[maxn], str2[maxn];
int dp[maxn][maxn];

void getTraverse(int len)
{
	int i = 1;
	while(len) str2[i++] = str1[len--];
	str2[i] = '\0';
}

int max(int a, int b){
	return a > b ? a : b;
}

int LCS(int len)
{
	int i, j;
	memset(dp, 0, sizeof(dp));
	for(i = 1; i <= len; ++i){
		for(j = 1; j <= len; ++j)
			if(str1[i] == str2[j]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	}
	return dp[len][len];
}

int main()
{
	int n, len;
	while(scanf("%d", &n) == 1){
		scanf("%s", str1 + 1);
		len = strlen(str1 + 1);
		getTraverse(len);
		printf("%d\n", len - LCS(len));
	}
	return 0;
}