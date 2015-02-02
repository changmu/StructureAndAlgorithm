////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-25 19:18:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2003
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	double n, t;
	while( scanf( "%lf", &n ) == 1 )
		printf( "%.2lf\n", n >= 0 ? n : -n );
	return 0;
}