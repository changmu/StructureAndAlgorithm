////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-25 19:17:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define A1 s += 30
#define A2 s += 31

bool runnian( int n ){
	return n % 4 == 0 && n % 100 != 0 || n % 400 == 0;
}

int main(){
	int y, m, d, s;
	char a; //ÈÓµô×Ö·û	
	while( scanf( "%d%c%d%c%d", &y, &a, &m, &a, &d ) != EOF ){
		s = 0;
		s += d;
		switch( m ){
			case 12: A1;
			case 11: A2;
			case 10: A1;
			case 9: A2;
			case 8: A2;
			case 7: A1;
			case 6: A2;
			case 5: A1;
			case 4: A2;
			case 3: runnian( y ) == 1 ? ( s += 29 ) : ( s += 28 ) ; 
			case 2: A2;
			default: ;
		}
		printf( "%d\n", s );
	}	
	return 0;
}