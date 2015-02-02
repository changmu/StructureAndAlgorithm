////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-24 16:10:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2522
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:356KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 100002

bool vis[maxn];

int main()
{
    int n, i, t, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n < 0){
            printf("-"); n = -n;
        }
        if(n == 1){
            printf("1\n"); continue;
        }        
        memset(vis, 0, sizeof(bool) * n);
        printf("0."); m = 1; vis[0] = 1;
        while(!vis[m]){
            vis[m] = 1; m *= 10;
            printf("%d", m / n);
            m %= n;
        }
        printf("\n");
    }
    return 0;
}