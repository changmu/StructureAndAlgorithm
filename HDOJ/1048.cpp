////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-26 20:47:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1048
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char str[220];

int main()
{
    while(gets(str)){
        if(!strcmp(str, "ENDOFINPUT")) break;
        else if(!strcmp(str, "START") || !strcmp(str, "END")) continue;
        for(int i = 0; str[i]; ++i){
            if(isalpha(str[i])) str[i] = ((str[i] - 'A') + 26 - 5) % 26 + 'A';
        }
        puts(str);
    }
    return 0;
}

