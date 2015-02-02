////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-25 18:41:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2011
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int n, m;
	double s;
	scanf( "%d", &n );
	while( n-- ){
		scanf( "%d", &m );
		s = 0;
		int i = 1;
		for( int j = 1; j <= m; ++j ){
			s += 1.0 / j * i;
			i = -i;
		}
		printf( "%.2lf\n", s );
	}
	return 0;
}