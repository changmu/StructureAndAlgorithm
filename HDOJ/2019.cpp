////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-26 16:05:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2019
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
int cmp( const void *a, const void *b ){
	return *(int *)a - *(int *)b;
}
int main(){
	int n, m, t;
	while( scanf( "%d%d", &n, &m ), n || m ){
		int *a = (int *)malloc( sizeof(int) * (n + 1) );
		int i = 1;
		a[0] = m;
		while( i <= n )
			scanf( "%d", &a[i++] );
		qsort( a, n + 1, sizeof(int), cmp );
		for( int i = 0; i != n; ++i )
			printf( "%d ", a[i] );
		printf( "%d\n", a[n] );
		free(a);
	}
	return 0;
}