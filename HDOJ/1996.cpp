////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-27 10:16:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1996
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

__int64 pow3[32] = {1, 3, 9, 27};

int main()
{
    int n, i, t;
    for(i = 4; i < 32; ++i)
        pow3[i] = pow3[i-1] * 3;    
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%I64d\n", pow3[n]);
    }
    return 0;
}
