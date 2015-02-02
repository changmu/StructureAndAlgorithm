////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-25 19:16:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2007
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int x, y, s0, s1;
	while( scanf( "%d%d", &x, &y ) == 2 ){
		s0 = s1 = 0;
		if( x > y ){
			int t = x;
			x = y;
			y = t;
		}
		if( x % 2 == 0 ){
			int t = x, t1 = x + 1;
			while( t <= y ){
				s0 += t * t;
				t += 2;
			}
			while( t1 <= y ){
				s1 += t1 * t1 * t1;
				t1 += 2;
			}
		}
		else{
			int t = x, t1 = x + 1;
			while( t <= y ){
				s1 += t * t * t;
				t += 2;
			}
			while( t1 <= y ){
				s0 += t1 * t1;
				t1 += 2;
			}
		}
		printf( "%d %d\n", s0, s1 );
	}
	return 0;
}