////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-12-15 07:26:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1796
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:1076KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int p[12], que[10000], id;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a / abs(gcd(a, b)) * b;
}

int nop(int n, int k) {
    int sum = 0, i, j, t; id = 0;
    que[id++] = -1;
    for (i = 0; i < k; ++i) {
        t = id;
        for (j = 0; j < t; ++j) {
            que[id] = lcm(p[i], que[j]) * -1;
            sum += n / que[id++];
        }
    }
    return sum;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int n, m, i;
    while (scanf("%d%d", &n, &m) == 2) {
        for (i = 0; i < m; ++i) {
            scanf("%d", &p[i]);
            if (p[i] <= 0 || p[i] >= n) --i, --m;
        }
        printf("%d\n", nop(n - 1, m));
    }
    return 0;
}