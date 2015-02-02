////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-25 19:19:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2002
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define pi 3.1415927

int main(){
	double r;
	while( scanf( "%lf", &r ) == 1 )
		printf( "%.3lf\n", r*r*r * pi * 4 / 3 );
	return 0;
}