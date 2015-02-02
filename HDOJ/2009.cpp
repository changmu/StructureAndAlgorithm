////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-25 18:44:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2009
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>

int main(){
	int n0, m;
	double s, n;
	while( scanf( "%d%d", &n0, &m ) == 2 ){
		n = n0;
		s = n;
		while( --m ){
			n = sqrt( n );
			s += n;
		}
		printf( "%.2lf\n", s );
	}
	return 0;
}