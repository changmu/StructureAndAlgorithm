////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-26 20:41:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4861
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
    int k, p;
    while(scanf("%d%d", &k, &p) != EOF){
        if(k / (p-1) % 2) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}



