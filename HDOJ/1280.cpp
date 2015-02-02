////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-19 17:31:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1280
////Problem Title: 
////Run result: Accept
////Run time:640MS
////Run memory:17868KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
int a[3001], b[4500000];

int cmp( const void *a, const void *b ){
    return *(int *)b - *(int *)a;
}

int main(){
    int n, m;
    while( scanf( "%d%d", &n, &m ) == 2 ){
        int n0 = n, i0 = 0, i1 = 0;
        while( n0-- )
            scanf( "%d", &a[i0++] );
        for( int i = 0; i != n - 1; ++i )
            for( int j = i + 1; j != n; ++j )
                b[i1++] = a[i] + a[j];
        qsort( b, n * ( n - 1 ) / 2, sizeof( int ), cmp );
        for( int i = 0; i != m; ++i ){
            printf( "%d", b[i] );
            if( i == m - 1 )
                printf( "\n" );
            else
                printf( " " );
        }
    }
    return 0;
}
