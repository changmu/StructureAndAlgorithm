////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-26 21:17:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1058
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:280KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define maxn 5845

int dp[maxn] = {1, 1};
int a, b, c, d;
const char *sam[] = { "st", "nd", "rd", "th" };

int min(int u, int v, int x, int y)
{
    int tmp = u;
    if(tmp > v) tmp = v;
    if(tmp > x) tmp = x;
    if(tmp > y) tmp = y;

    if(tmp == u) ++a;
    if(tmp == v) ++b;
    if(tmp == x) ++c;
    if(tmp == y) ++d;
    
    return tmp;
}

const char *f(int n)
{
    if(n % 10 == 1 && n % 100 != 11) return sam[0];
    if(n % 10 == 2 && n % 100 != 12) return sam[1];
    if(n % 10 == 3 && n % 100 != 13) return sam[2];
    return sam[3];
}

int main()
{
    int i, n;
    a = b = c = d = 1;
    for(i = 2; i < maxn; ++i)
        dp[i] = min(dp[a] * 2, dp[b] * 3, dp[c] * 5, dp[d] * 7);
    while(scanf("%d", &n), n)
        printf("The %d%s humble number is %d.\n", n, f(n), dp[n]);
    return 0;
}
