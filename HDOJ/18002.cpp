////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-12-09 12:52:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1800
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:1112KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 3011

int ELFhash(char *key) {
    unsigned long h = 0, g;
    while(*key) {
        h = (h << 4) + *key++;
        g = h & 0xf0000000L;
        if(g) h ^= g >> 24;
        h &= ~g;
    }
    return h;
}

char str[32];
int f[maxn], g[maxn], ans, N;

void hashFun(char *str) {
    int k, t;
    while(*str == '0') ++str;
    k = ELFhash(str);
    t = k % maxn;
    while(f[t] && g[t] != k)
        if(++t == maxn) t = 0;
    g[t] = k;
    if(++f[t] > ans) ans = f[t];
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    while(scanf("%d", &N) == 1) {
        memset(f, 0, sizeof(f));
        ans = 1;
        while(N--) {
            scanf("%s", str);
            hashFun(str);
        }
        printf("%d\n", ans);
    }
    return 0;
}