////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-23 23:33:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1012
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int jiecheng( int n ){
	if( n == 0 || n == 1 )
		return 1;
	return n * jiecheng( n - 1 );
}

int main(){
	int n;
	double e = 0;
	printf( "n e\n" );
	printf( "- -----------\n0 1\n1 2\n2 2.5\n" );
	for( int n = 0; n != 3; ++n )
		e += 1.0 / jiecheng( n );
	for( int n = 3; n != 10; ++n )
		printf( "%d %.9lf\n", n, e += 1.0 / jiecheng( n ) );
	return 0;
}