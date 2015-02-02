////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-22 00:13:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2563
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int a[21] = { 0, 3, 7 };
	for( int i = 3; i != 21; ++i )
		a[i] = 2 * a[i - 1] + a[i - 2];
	int c, n;
	scanf( "%d", &c );
	while( c-- && scanf( "%d", &n ) )
		printf( "%d\n", a[n] );	
	return 0;
}