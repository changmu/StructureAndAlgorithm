////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-12-09 10:40:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1496
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:8928KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 1000002

int hash1[maxn], hash2[maxn];
int sam[102];

int main() {
    int a, b, c, d, i, j, ans, tmp;
    for(i = 1; i <= 100; ++i)
        sam[i] = i * i;
    while(scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
        if(a>0&&b>0&&c>0&&d>0||a<0&&b<0&&c<0&&d<0) {
            printf("0\n"); continue;
        }
        memset(hash1, 0, sizeof(hash1));
        memset(hash2, 0, sizeof(hash2));
        ans = 0;

        for(i = 1; i <= 100; ++i)
            for(j = 1; j <= 100; ++j) {
                tmp = a * sam[i] + b * sam[j];
                if(tmp > 0) ++hash1[tmp];
                else ++hash2[-tmp];
            }
        for(i = 1; i <= 100; ++i)
            for(j = 1; j <= 100; ++j) {
                tmp = c * sam[i] + d * sam[j];
                if(tmp >= 0) ans += hash2[tmp];
                else ans += hash1[-tmp];
            }
        printf("%d\n", ans * 16);
    }
    return 0;
}