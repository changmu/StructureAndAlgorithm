////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-01-26 21:05:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2025
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main(){
	char s[101], ch;
	while( scanf( "%s", s ) == 1 ){
		ch = s[0];
		//扫描最大字符
		for( int i = 1; s[i] != '\0'; ++i )
			if( s[i] > ch ) ch = s[i];
		//输出
		for( int i = 0; s[i] != '\0'; ++i )
			if( s[i] == ch )
				printf( "%c%s", ch, "(max)");
			else putchar( s[i] );
		putchar( '\n' );		
	}
	return 0;
}