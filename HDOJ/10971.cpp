////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-27 21:51:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1097
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

const char *sam[] = {"0", "1", "2486", "3971", "46", "5", "6", "7931", "8426", "91"};

int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b) == 2)
        printf("%c\n", sam[a % 10][(b-1) % strlen(sam[a%10])]);
    return 0;
}