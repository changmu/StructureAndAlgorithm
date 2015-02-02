////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-12-09 11:25:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1496
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1328KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 30011
int f[maxn], g[maxn], sam[102];

int hash(int x) {
    int tmp = x % maxn;
    if(tmp < 0) tmp += maxn;
    while(f[tmp] && g[tmp] != x)
        if(++tmp == maxn) tmp = 0;
    return tmp;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int a, b, c, d, ans, i, j, s, tmp;
    for(i = 1; i <= 100; ++i)
        sam[i] = i * i;
    while(scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
        if(a>0&&b>0&&c>0&&d>0||a<0&&b<0&&c<0&&d<0) {
            printf("0\n"); continue;
        }
        memset(f, ans = 0, sizeof(f));
        for(i = 1; i <= 100; ++i)
            for(j = 1; j <= 100; ++j) {
                s = a * sam[i] + b * sam[j];
                tmp = hash(s);
                ++f[tmp];
                g[tmp] = s;
            }
        for(i = 1; i <= 100; ++i)
            for(j = 1; j <= 100; ++j) {
                s = -(c * sam[i] + d * sam[j]);
                ans += f[hash(s)];
            }
        printf("%d\n", ans * 16);
    }
    return 0;
}