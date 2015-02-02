////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-23 11:44:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1020
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int n, i;
	char ch, a = '0';
	scanf( "%d", &n );
	getchar();
	while( n-- ){
		i = 0;
		while( (ch = getchar()) != '\n' ){
			if( i == 0 )
				a = ch, ++i;
			else if( a == ch )
				++i;
			else if( i > 1 ){
				printf( "%d%c", i, a );
				i = 1;
				a = ch;
			}
			else if( i == 1 )
				putchar( a ), a = ch;			
		}
		if( i > 1 )
			printf( "%d%c", i, a );
		else
			putchar( a );		
		putchar( '\n' );
	}
	return 0;
}