////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-23 22:38:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1032
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int len( int n ){
    int i = 1;
    while( n != 1 ){
        if( n & 1 )
            n = 3 * n + 1;
        else
            n >>= 1;
        ++i;
    }
    return i;
}

int main(){
    int i, j, maxlen, ii, jj;
    while( scanf( "%d%d", &i, &j ) == 2 ){
         i < j ? ( ii = i, jj = j ) : ( ii = j, jj = i );
         maxlen = 0;
         while( ii <= jj ){
            int t = len( ii++ );
            if( t > maxlen )
                maxlen = t;
         }
         printf( "%d %d %d\n", i, j, maxlen );
    }
    return 0;
}
