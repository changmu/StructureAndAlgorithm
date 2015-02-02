////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-23 13:40:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1212
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define maxn 1002

char str[maxn];

int main()
{
    int m, ans, i;
    while(scanf("%s%d", str, &m) != EOF){
        ans = 0;
        for(i = 0; str[i]; ++i){
            ans = (ans * 10 + (str[i] - '0') % m) %m;
        }
        printf("%d\n", ans);
    }
    return 0;
}