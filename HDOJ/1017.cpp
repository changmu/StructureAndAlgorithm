////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-03-11 08:51:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1017
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:228KB
//////////////////System Comment End//////////////////
//Ä£Äâ
//2014-3-11 08:19:16
#include <stdio.h>

int main(){
    int t, n, m, a, b, count, time;
    scanf("%d", &t);
    while(t--){
		time = 1;
        while(scanf("%d%d", &n, &m), n || m){
            for(a = 1, count = 0; a < n - 1; ++a)
                for(b = a + 1; b < n; ++b)
                    if((a*a + b*b + m) % (a * b) == 0)
                        ++count;
            printf("Case %d: %d\n", time++, count);
        }
        if(t) printf("\n");
    }
    return 0;
}