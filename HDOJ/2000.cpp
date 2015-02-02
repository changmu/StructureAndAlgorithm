////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-25 19:20:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2000
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>

int cmp( const void *a, const void *b ){
    char *aa = (char *)a, *bb = (char *)b;
    if( *aa < *bb )
        return -1;
    else if( *aa > *bb )
        return 1;
    else
        return 0;
}

int main(){
    char s[3];
    while( scanf( "%c%c%c", &s[0], &s[1], &s[2] ) == 3 ){
        getchar();
        qsort( s, 3, sizeof( char ), cmp );
        printf( "%c %c %c\n", s[0], s[1], s[2] );
    }
    return 0;
}
