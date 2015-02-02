////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-27 23:51:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1200
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

char map[200][30];
char str[210];

int main()
{
    int n, i, j, k;
    while(scanf("%d", &n), n){
        scanf("%s", str);
        i = j = 1; k = 0;
        while(1){
            while(j <= n) map[i][j++] = str[k++];
            if(!str[k]) break; ++i; j = n;
            while(j > 0) map[i][j--] = str[k++];
            if(!str[k]) break; ++i; j = 1;
        }
        for(j = 1; j <= n; ++j)
            for(k = 1; k <= i; ++k) putchar(map[k][j]);
        printf("\n");
    }
    return 0;
}