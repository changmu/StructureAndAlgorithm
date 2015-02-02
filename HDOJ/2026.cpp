////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-26 21:19:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2026
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char s[101];
	int ok;
	while( gets(s) ){
		if( isalpha(s[0]) )
			s[0] = toupper( s[0] );
		for( int i = 0; s[i] != '\0'; ++i )
			if( s[i] == ' ' ) s[i + 1] = toupper( s[i + 1] );
		puts( s );
	}
	return 0;
}