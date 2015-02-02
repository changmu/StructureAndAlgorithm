////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-10 14:04:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1215
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:2184KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define MAX 500000
int a[MAX + 1];

void dabiao(){
    for( int i = 1; i <= MAX / 2; ++i ){
        for( int j = i + i; j <= MAX; j += i )
            a[j] += i;
    }
}

int main(){
    dabiao();
    int t, n;
    scanf( "%d", &t );
    while( t-- && scanf( "%d", &n ) ){
        printf( "%d\n", a[n] );
    }
    return 0;
}
