////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-13 13:26:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2135
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

char G[12][12];

void solve(int n, int m) {
    int i, j;
    if(m == 0) {
        for(i = 1; i <= n; ++i) {
            for(j = 1; j <= n; ++j)
                printf("%c", G[i][j]);
            printf("\n");
        }
    } else if(m == 1) {
        for(j = 1; j <= n; ++j) {
            for(i = n; i >= 1; --i)
                printf("%c", G[i][j]);
            printf("\n");
        }
    } else if(m == 2) {
        for(i = n; i > 0; --i) {
            for(j = n; j > 0; --j)
                printf("%c", G[i][j]);
            printf("\n");
        }
    } else if(m == 3) {
        for(j = n; j > 0; --j) {
            for(i = 1; i <= n; ++i)
                printf("%c", G[i][j]);
            printf("\n");
        }
    }
} 

int main() {
    int n, m, i, j;
    while(scanf("%d%d", &n, &m) == 2) {
        for(i = 1; i <= n; ++i)
            scanf("%s", G[i] + 1);
        m = (m % 4 + 4) % 4;
        solve(n, m);
    }
    return 0;
}