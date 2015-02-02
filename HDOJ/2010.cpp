////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-24 22:29:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2010
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>

bool f( int m ){
	int a, b, c;
	a = m % 10;
	b = m % 100 / 10;
	c = m / 100;
	if( m == a*a*a + b*b*b + c*c*c )
		return true;
	return false;
}

int main(){
	int m, n, i;
	while( scanf( "%d%d", &m, &n ) == 2 ){
		while( m <= n ){
			if( f(m) ){
				printf( "%d", m);
				++m;
				break;
			}
			if( m == n )
				printf( "no\n" );
			++m;
		}	
		if( m <= n ){
			for( int i = m; i <= n; ++i ){
				if( f(i) )
					printf( " %d", i);
			}
			printf( "\n" );
		}
	}
	return 0;
}