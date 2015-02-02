////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-17 09:31:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2553
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int arr[] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724};
    int n;
    while(scanf("%d", &n), n)
        printf("%d\n", arr[n]);
    return 0;
}