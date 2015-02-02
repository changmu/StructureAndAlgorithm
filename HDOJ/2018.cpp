////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-26 15:37:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2018
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int n, a[55] = { 0, 1, 2, 3 };
	for( int i = 4; i != 55; ++i )
		a[i] = a[i - 1] + a[i - 3];
	while( scanf( "%d", &n ), n )		
		printf( "%d\n", a[n] );
	return 0;
}