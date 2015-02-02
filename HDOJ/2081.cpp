////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-30 15:56:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2081
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	char s[12];
	int n;
	scanf("%d", &n);
	while(n-- && scanf("%s", s)){
		s[5] = '6';
		puts(s + 5);
	}
	return 0;
}