////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-26 21:54:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2027
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

int main(){
	char s[101];
	int a, e, i, o, u, n;
	scanf( "%d", &n );
	getchar();
	while( n-- && gets(s) ){
		a = e = i = o = u = 0;
		for( int j = 0; s[j] != '\0'; ++j )
			switch (s[j]){
			case 'a': ++a; break;
			case 'e': ++e; break;
			case 'i': ++i; break;
			case 'o': ++o; break;
			case 'u': ++u; break;
			}
		printf( "a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", a, e, i, o, u );
		if( n )
			putchar('\n');
	}
	return 0;
}