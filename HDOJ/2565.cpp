////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-24 23:17:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2565
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int t, n;
	scanf( "%d", &t );
	while( t-- && scanf( "%d", &n ) ){
		for( int i = 1; i <= n; ++i ){
			for( int j = 1; j <= n; ++j )
				if( i == j || i + j == n + 1 ) {
					putchar( 'X' );
					if( j > n / 2 ) break;
				}				
				else putchar( ' ' );			
			putchar( '\n' );			
		}
			putchar( '\n' );
	}
	return 0;
}