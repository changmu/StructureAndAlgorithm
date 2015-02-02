////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-09 17:14:39
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1001
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main(){
    int n, sum;
    while( scanf( "%d", &n ) == 1 ){
        if( n & 1 )
            sum = ( 1 + n ) / 2 * n;
        else
            sum = n / 2 * ( 1 + n );
        printf( "%d\n\n", sum );
    }
    return 0;
}
