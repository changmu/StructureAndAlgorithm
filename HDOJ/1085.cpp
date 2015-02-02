////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-25 19:42:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1085
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c), a || b || c){
        if(!a) printf("1\n");
        else if(a + 2 * b < 4) printf("%d\n", a + 2 * b + 1);
        else printf("%d\n", a + 2 * b + 5 * c + 1);
    }
    return 0;
}
