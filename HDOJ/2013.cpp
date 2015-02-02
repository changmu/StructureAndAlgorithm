////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-25 18:33:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2013
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int n, s;
	while( scanf( "%d", &n ) == 1 ){
		s = 1;
		while( --n )
			s = (s + 1) * 2;
		printf( "%d\n", s );
	}
	return 0;
}