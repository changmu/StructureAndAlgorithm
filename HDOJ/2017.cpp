////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-26 15:15:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2017
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main(){
	int n, s;
	char ch;
	scanf( "%d", &n );
	getchar();
	while( n-- ){
		s = 0;
		while( (ch = getchar()) != '\n' )
			if( ch >= '0' && ch <= '9' )
				++s;
		printf( "%d\n", s );
	}
	return 0;
}