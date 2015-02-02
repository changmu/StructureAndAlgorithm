////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-27 09:54:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1995
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>

__int64 pow2[66] = {1, 2, 4, 8, 16};

int main()
{
    int n, a, i, t;
    for(i = 5; i < 65; ++i)
        pow2[i] = pow2[i-1] << 1;    
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &a);
        n = n - a + 1;
        printf("%I64d\n", pow2[n - 1]);
    }
    return 0;
}
