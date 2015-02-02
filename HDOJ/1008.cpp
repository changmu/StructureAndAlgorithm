////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-23 23:11:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1008
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int n, t, now, s;
	while( scanf( "%d", &n ), n ){
		now = s = 0;
		while( n-- && scanf( "%d", &t ) ){
			if( t > now )
				s = s + 6 * ( t - now ) + 5, now = t;
			else if( t < now )
				s = s + 4 * ( now - t ) + 5, now = t;
			else
				s += 5;
		}
		printf( "%d\n", s );
	}
	return 0;
}