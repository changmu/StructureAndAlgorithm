////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-25 19:17:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2006
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int s, n, t;
	while( scanf( "%d", &n ) == 1 ){
		s = 1;
		while( n-- && scanf( "%d", &t ) )
			if( t & 1 )
				s *= t;
		printf( "%d\n", s );
	}
	return 0;	
}