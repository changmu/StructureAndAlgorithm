////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-26 20:39:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2024
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

int main(){
	char s[51];
	int n, ok;
	scanf( "%d", &n );
	getchar();
	while( n-- ){
		gets(s);
		ok = 1;
		if( !(s[0] == '_' || s[0] >= 'A' && s[0] <= 'Z'|| s[0] >= 'a' && s[0] <= 'z' ) ){
			printf( "no\n" );
			continue;
		}
		for( int i = 1; s[i] != '\0'; ++i ){
			if( !(s[i] >= '0' && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'Z'|| s[i] >= 'a' && s[i] <= 'z' || s[i] == '_' ) ){
				printf( "no\n" );
				ok = 0;
				break;
			}
		}
		if( ok )
			printf( "yes\n" );
	}
	return 0;
}