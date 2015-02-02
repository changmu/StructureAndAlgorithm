////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-25 19:21:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1262
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#define MAX 10000 + 2
int a[MAX];

void prime(){
    int i, j, t = sqrt( MAX ) + 1;
    a[0] = a[1] = 1; //'1' stands for not a prime
    for( i = 2; i != t; ++i ){
        if( a[i] )
            continue;
        for( j = i * i; j < MAX; j += i )
            a[j] = 1;
    }
}

int main(){
    int m, t;
    prime();
    while( scanf( "%d", &m ) == 1 ){
        t = m / 2;
        for( int i = 0; i != t; ++i ){
            if( !a[t - i] && !a[t + i] ){
                printf( "%d %d\n", t - i, t + i );
                break;
            }
        }
    }
    return 0;
}