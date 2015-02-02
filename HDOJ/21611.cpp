////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-09-22 08:34:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2161
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>

bool isPrime(int n) {
    if(n <= 2) return false;
    int t = sqrt((double) n);
    for(int i = 2; i <= t; ++i)
        if(n % i == 0) return 0;
    return 1;
}

int main() {
    int n, count = 0;
    while(scanf("%d", &n), n > 0) {
        printf("%d: ", ++count);
        printf(isPrime(n) ? "yes\n" : "no\n");
    }
    return 0;
}