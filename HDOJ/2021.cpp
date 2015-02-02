////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-26 16:40:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2021
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main(){
	int n, s, t;
	while( scanf( "%d", &n ), n ){
		s = 0;
		while( n-- && scanf( "%d", &t ) )
			while(t){
				while( t >= 100 )
					t -= 100, ++s;
				if( t >= 50 )
					t -= 50, ++s;
				while( t >= 10 )
					t -= 10, ++s;
				while( t >= 5 )
					t -= 5, ++s;
				while( t >= 2 )
					t -= 2, ++s;
				if( t == 1 )
					t -= 1, ++s;
			}
		printf( "%d\n", s );
	}
	return 0;
}