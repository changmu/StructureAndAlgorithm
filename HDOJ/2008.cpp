////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-25 18:45:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2008
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int n, a, b, c;
	double t;
	while( scanf( "%d", &n ), n ){
		a = b = c = 0;
		while( n-- ){
			scanf( "%lf", &t );
			if( t < 0 )
				++a;
			else if( t == 0 )
				++b;
			else
				++c;
		}
		printf( "%d %d %d\n", a, b, c );
	}
	return 0;
}