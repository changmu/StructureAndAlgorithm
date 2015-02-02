////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-23 22:44:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1229
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int a, b, k, ok;
	while( scanf( "%d%d%d", &a, &b, &k ), a || b ){
		ok = 0;
		int i = a, j = b;
		while( k-- ){
			if( i % 10 == j % 10 )
				i /= 10, j /= 10;
			else{
				ok = 1;
				break;
			}
		}
		if( !ok )
			printf( "-1\n" );
		else
			printf( "%d\n", a + b );
	}
	return 0;
}