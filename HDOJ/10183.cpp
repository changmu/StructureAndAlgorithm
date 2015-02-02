////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-24 18:14:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1018
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
    int t, n, count;
    double temp;
    scanf( "%d", &n );
    while( n-- && scanf( "%d", &t ) ){
        count = 1;
        temp = 1;
        for( int i = 1; i <= t; ++i ){
            temp *= i;
            while( temp > 1000000 ){         
                temp = temp / 1000000;
                count += 6;
            }
        }
        int tem = temp;
        while( tem /= 10 )
            ++count;
        printf( "%d\n", count );        
    }
    return 0;
}