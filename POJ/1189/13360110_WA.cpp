#include <stdio.h>
#include <string.h>
#define maxn 60

struct Node{
    __int64 a, b; //fenzi fenmu
} dp[maxn][maxn];
char map[maxn][maxn];

__int64 gcd(__int64 a, __int64 b){
    return b ? gcd(b, a % b) : a;
}

Node huajian(__int64 a, __int64 b){
    __int64 c = gcd(a, b);
    a /= c; b /= c;
    Node t; t.a = a; t.b = b;
    return t;
}

Node addTwo(__int64 a, __int64 b, __int64 c, __int64 d)
{
    __int64 x, y;
    x = b * c + a * d; y = b * d;
    return huajian(x, y);
}

int main()
{
    int n, m, i, j, a, b, c, d;
    char ch;
    while(scanf("%d%d", &n, &m) == 2){
        memset(dp, 0, sizeof(dp));
        for(i = 1; i <= n; ++i){
            j = 0;
            while(true)
                if((ch = getchar()) != ' ' && ch != '\n'){
                    map[i][++j] = ch;
                    if(j == i) break;
                }
        }
        dp[1][1].a = dp[1][1].b = 1;
        for(i = 1; i <= n; ++i)
            for(j = 1; j <= i; ++j){
                if(dp[i][j].b == 0) continue;
                if(map[i][j] == '*'){
                    if(dp[i+1][j].b == 0)
                        dp[i+1][j] = huajian(dp[i][j].a, dp[i][j].b * 2);
                    else dp[i+1][j] = addTwo(dp[i][j].a, dp[i][j].b * 2, dp[i+1][j].a, dp[i+1][j].b);
                    if(dp[i+1][j+1].b == 0)
                        dp[i+1][j+1] = huajian(dp[i][j].a, dp[i][j].b * 2);
                    else dp[i+1][j+1] = addTwo(dp[i][j].a, dp[i][j].b * 2, dp[i+1][j+1].a, dp[i+1][j+1].b);
                }else{
                    if(dp[i+2][j+1].b == 0) dp[i+2][j+1] = dp[i][j];
                    else dp[i+2][j+1] = addTwo(dp[i][j].a, dp[i][j].b, dp[i+2][j+1].a, dp[i+2][j+1].b);
                }
            }
        if(dp[n+1][m+1].b == 0)
            printf("0/1\n");
        else printf("%I64d/%I64d\n", dp[n+1][m+1].a, dp[n+1][m+1].b);
    }
    return 0;
}