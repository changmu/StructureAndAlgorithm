////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-25 22:43:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1085
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 8010

int c1[maxn], c2[maxn];

int main()
{
    int a, b, c, i, j, k, sum;
    while(scanf("%d%d%d", &a, &b, &c), a || b || c){
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        for(i = 0; i <= a; ++i) c1[i] = 1;
        for(i = 2, sum = a + 2 * b; i <= 5; i += 3, sum += 5 * c){
            for(j = 0; j <= sum; ++j)
                for(k = j; k <= sum; k += i)
                    c2[k] += c1[j];
                for(k = 0; k <= sum; ++k){
                    c1[k] = c2[k]; c2[k] = 0;
                }
        }
        for(i = 1; i <= sum; ++i){
            if(!c1[i]){ printf("%d\n", i); break; }
        }
    }
    return 0;
}
