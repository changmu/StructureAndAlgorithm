////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-26 17:26:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2022
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <malloc.h>
int main(){
	int *a, m, n, t, x, y, s;
	while( scanf( "%d%d", &m, &n ) != EOF ){
		a = (int *)malloc( sizeof(int) * m * n );
		for( int i = 0; i != m * n; ++i )
			scanf( "%d", &a[i] );
		t = abs(a[0]); x = 1, y = 1; s = a[0];
		for( int i = 1; i != n * m; ++i )
			if( abs(a[i]) > t ){
				t = abs(a[i]); s = a[i];
				x = (i + 1) / n + 1;
				y = (i + 1) % n;
				if( !y ) y = n, --x;
			}
		printf( "%d %d %d\n", x, y, s );		
		free(a);
	}
	return 0;
}