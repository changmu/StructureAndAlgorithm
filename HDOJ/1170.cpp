////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-27 23:29:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1170
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>

void f(char ch, int a, int b)
{
    if(ch == '+') printf("%d\n", a + b);
    else if(ch == '-') printf("%d\n", a - b);
    else printf("%d\n", a * b);
}

int main()
{
    int a, b, t;
    char str[2];
    scanf("%d", &t);
    while(t--){
        scanf("%s%d%d", str, &a, &b);
        if(str[0] != '/') f(str[0], a, b);
        else if(a % b == 0) printf("%d\n", a / b);
        else printf("%.2lf\n", (double)a / b);
    }
    return 0;
}