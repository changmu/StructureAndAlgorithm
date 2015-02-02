////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-28 08:51:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1211
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
//hdu1211
#include <stdio.h>
typedef __int64 lld;

lld f(lld c, lld d, lld n)
{
    if(d == 0) return 1 % n;
    if(d == 1) return c % n;
    lld tmp = f(c, d >> 1, n);
    tmp = tmp * tmp % n;
    if(d & 1) tmp = tmp * c % n;
    return tmp;
}

int main()
{
    lld p, q, e, l, c, n, fn, d, i;
    char ch;
    while(scanf("%I64d%I64d%I64d%I64d", &p, &q, &e, &l) != EOF){
        n = p * q; fn = (p - 1) * (q - 1);
        for(i = 1; ; ++i)
            if(i * e % fn == 1) break;
        d = i;
        while(l--){
            scanf("%I64d", &c);
            printf("%c", f(c, d, n));
        }
        printf("\n");
    }
    return 0;
}