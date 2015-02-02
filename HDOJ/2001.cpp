////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-25 19:19:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2001
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>

int main(){
    double a, b, x, y, t, t1;
    while( scanf( "%lf%lf%lf%lf", &a, &b, &x, &y ) != EOF ){
        t = ( a - x ) * ( a - x );
        t1 = ( b - y ) * ( b - y );
        printf( "%.2lf\n", sqrt( t + t1 ) );
    }
    return 0;
}
