////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-25 18:43:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2012
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>

bool prime( int n ){
	int t = sqrt( n );
	for( int i = 2; i <= t; ++i )
		if( n % i == 0 )
			return false;
	return true;
}

int main(){
	int x, y;
	while( scanf( "%d%d", &x, &y ), x || y ){
		while( x <= y ){
			if( !prime( x*x + x + 41 ) ){
				printf( "Sorry\n" );
				break;
			}
			++x;
		}
		if( x > y )
			printf( "OK\n" );
	}
	return 0;
}