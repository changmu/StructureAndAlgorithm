////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-27 22:34:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1161
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    char ch;
    while(scanf("%c", &ch) != EOF){
        if(ch >= 'A' && ch <= 'Z') ch = ch - 'A' + 'a';
        putchar(ch);
    }
    return 0;
}