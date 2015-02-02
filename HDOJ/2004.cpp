////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-25 19:18:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2004
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int n;
	while( scanf( "%d", &n ) == 1 ){
		if( n > 100 || n < 0 ){
		    printf( "Score is error!\n" );
			continue;
		}
		n /= 10;				
		switch( n ){
			case 10: 
			case 9: printf( "A\n" );  break;
			case 8: printf( "B\n" );  break;
			case 7: printf( "C\n" );  break;
			case 6: printf( "D\n" );  break;
			default: printf( "E\n" );
		}
	}
	return 0;
}