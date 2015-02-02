////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-20 19:26:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1018
////Problem Title: 
////Run result: Accept
////Run time:953MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>

int main(){
	int t, n;
	double tem;
	scanf( "%d", &t );
	while( t-- && scanf( "%d", &n ) ){		
		tem = 1;
		while( n )
			tem += log10( n-- );
		printf( "%d\n", (int)tem );
	}
	return 0;
}