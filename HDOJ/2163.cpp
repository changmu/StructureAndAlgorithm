////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-26 20:59:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2163
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

char str[56];

bool f()
{
    int len = strlen(str), i = 0, j;
    j = len - 1;
    while(i <= j){
        if(str[i] == str[j]){
            ++i; --j;
        }else return 0;
    }
    return 1;
}

int main()
{
    int cas = 1;
    while(scanf("%s", str) != EOF){
        if(!strcmp(str, "STOP")) break;
        printf("#%d: ", cas++);
        if(f()) puts("YES");
        else puts("NO");
    }
    return 0;
}