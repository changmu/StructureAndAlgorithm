////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-26 16:20:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2020
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
int cmp( const void *a, const void *b ){
	return abs(*(int *)b) - abs(*(int *)a);
}
int main(){
	int n, m, t;
	while( scanf( "%d", &n ), n ){
		int *a = (int *)malloc( sizeof(int) * n );
		t = n;
		while( n-- )
			scanf( "%d", &a[n] );
		qsort( a, t, sizeof(int), cmp );
		for( int i = 0; i != t - 1; ++i )
			printf( "%d ", a[i] );
		printf( "%d\n", a[t - 1] );
		free(a);
	}
	return 0;
}