////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-01-23 22:41:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1201
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

bool run( int n ){
    if( ( n % 4 == 0 && n % 100 != 0 ) || ( n % 400 == 0 ) )
        return true;
    return false;
}

int main(){
    int t, y, m, d, s;
    scanf( "%d", &t );
    while( t-- ){
        scanf( "%d-%d-%d", &y, &m, &d );
        if( 2 == m && 29 == d )
            if( !run( y + 18 ) ){
                printf( "-1\n" );
                continue;
        }
        s = 18 * 365;
        for( int i = 1; i != 18; ++i ){ //改了一下这里
            if( run( y + i ) )
                ++s;
        }
        if( m > 2 && run( y + 18 ) )
            ++s;
        else if( m <= 2 && run( y ) )
            ++s;
        printf( "%d\n", s );
    }
    return 0;
}