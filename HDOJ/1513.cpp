////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-12-09 08:26:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1513
////Problem Title: 
////Run result: Accept
////Run time:327MS
////Run memory:1212KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;

#define maxn 5010

char str1[maxn], str2[maxn];
int len, dp[2][maxn];

void prepro() {
    int i = 1, j = len + 1;
    str2[j--] = '\0';
    while(str1[i]) str2[j--] = str1[i++];
}

int solve() {
    memset(dp, 0, sizeof(dp));
    int i, j, x;
    for(i = 1; i <= len; ++i) {
        x = i & 1;
        for(j = 1; j <= len; ++j) {
            if(str1[i] == str2[j])
                dp[x][j] = dp[!x][j-1] + 1;
            else dp[x][j] = max(dp[!x][j], dp[x][j-1]);
        }
    }
    return len - dp[len&1][len];
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    while(scanf("%d", &len) != EOF) {
        scanf("%s", str1 + 1);
        prepro();
        printf("%d\n", solve());
    }
    return 0;
}