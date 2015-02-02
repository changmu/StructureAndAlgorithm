////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-29 12:36:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2055
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int t, a;
	char ch;
	scanf("%d", &t);
	while(t-- && scanf("\n%c%d", &ch, &a))
		if(ch < 'a') printf("%d\n", ch - 'A' + 1 + a);
		else printf("%d\n", 'a' - ch - 1 + a);	
	return 0;
}