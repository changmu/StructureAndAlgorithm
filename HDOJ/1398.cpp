////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-25 19:08:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1398
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define maxn 302

int c1[maxn], c2[maxn];

int main()
{
    int n, i, j, k;
    while(scanf("%d", &n), n){
        for(i = 0; i <= n; ++i){
            c1[i] = 1; c2[i] = 0;
        }
        for(i = 2; i * i <= n; ++i){
            for(j = 0; j <= n; ++j)
                for(k = j; k <= n; k += i * i)
                    c2[k] += c1[j];        
            for(k = 0; k <= n; ++k){
                c1[k] = c2[k]; c2[k] = 0;
            }
        }
        printf("%d\n", c1[n]);
    }
    return 0;
}
