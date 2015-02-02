#include <stdio.h>
#include <string.h>
#define maxn 1000

char str1[maxn], str2[maxn];
int dp[maxn][maxn];

int max(int a, int b){ return a > b ? a : b; }

int LCS()
{
    int ans = 0;
    for(int i = 1, j; str1[i]; ++i){
        for(j = 1; str2[j]; ++j){
            if(str1[i] == str2[j]){
                dp[i][j] = dp[i-1][j-1] + 1;                
            }else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(dp[i][j] > ans) ans = dp[i][j]; 
        }
    }
    return ans;
}

int main()
{
    while(scanf("%s%s", str1 + 1, str2 + 1) == 2){
        printf("%d\n", LCS());
    }
    return 0;
}