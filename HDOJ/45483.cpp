////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-10 13:27:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4548
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:8060KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#define MAX 1000000
int a[MAX + 1], b[MAX + 1];
int sum( int );

void isprime(){
    a[0] = a[1] = 1; // '1' stands for not a prime
    int t = sqrt( MAX ) + 2;
    for( int i = 2; i != t; ++i ){
        if( a[i] )
            continue;
        for( int j = i * i; j <= MAX; j += i )
            a[j] = 1;
    }
}

void dabiao(){
    b[2] = 1;
    for( int i = 3; i <= MAX; ++i )
        if( !a[i] && !a[sum(i)] )
            b[i] = b[i - 1] + 1;
        else
            b[i] =b[i - 1];
}

int sum( int n ){
    int sum = 0;
    while( n ){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(){
    isprime();
    dabiao();
    int l, r, i = 1, t;
    scanf( "%d", &t );
    while( t-- && scanf( "%d%d", &l, &r ) ){
        printf( "Case #%d: %d\n", i++, b[r] - b[l - 1] );
    }
    return 0;
}
