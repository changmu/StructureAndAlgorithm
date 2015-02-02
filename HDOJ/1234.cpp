////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-28 09:43:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1234
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

int main()
{
    int t, n, h, m, s, u, v;
    char tmp[20], s1[20], s2[20];
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        u = 99999; v = -1;
        while(n--){
            scanf("%s%d:%d:%d", tmp, &h, &m, &s);
            s += h * 60 * 60 + m * 60;
            if(s < u){
                u = s; strcpy(s1, tmp);
            }
            scanf("%d:%d:%d", &h, &m, &s);
            s += h * 60 * 60 + m * 60;
            if(s > v){
                v = s; strcpy(s2, tmp);
            }
        }
        printf("%s %s\n", s1, s2);
    }
    return 0;
}
