////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-28 09:33:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1220
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int n, a, arr[] = {0, 0, 16};
    while(scanf("%d", &n) == 1){
        if(n < 3){
            printf("%d\n", arr[n]);
            continue;
        }
        a = (n*n*n - 4) * 8;
        a += (n*n*n - 5)*12*(n-2);
        a += (n-2)*(n-2)*6*(n*n*n - 6);
        a += (n-2)*(n-2)*(n-2)*(n*n*n-7);
        printf("%d\n", a >> 1);
    }
    return 0;
}