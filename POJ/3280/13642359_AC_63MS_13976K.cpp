#include <stdio.h>
#include <string.h>

#define maxn 2010

char str[maxn];
int dp[maxn][maxn];
struct Node {
    int add, del;
} cost[26];

int min(int a, int b) {
    return a < b ? a : b;
}

int getDele(char ch) {
    return cost[ch - 'a'].del;
}

int getAdd(char ch) {
    return cost[ch - 'a'].add;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int N, M, i, j, id, step, len;
    char buf[2];
    scanf("%d%d", &N, &M);
    scanf("%s", str);
    memset(cost, -1, sizeof(cost));
    while(M--) {
        scanf("%s", buf);
        id = buf[0] - 'a';
        scanf("%d%d", &cost[id].add, &cost[id].del);
    }
    len = strlen(str);
    for(step = 1; step < len; ++step)
        for(i = 0; i + step < len; ++i) {
            if(str[i] == str[i+step])
                dp[i][i+step] = dp[i+1][i+step-1];
            else {
                dp[i][i+step] = min(min(dp[i+1][i+step] + getDele(str[i]), dp[i][i+step-1] + getDele(str[i+step])), min(dp[i+1][i+step] + getAdd(str[i]), dp[i][i+step-1] + getAdd(str[i+step])));
            }
        }
    printf("%d\n", dp[0][len-1]);
    return 0;
}