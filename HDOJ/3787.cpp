////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-02-13 15:53:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3787
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <ctype.h>
#include <string.h>
char BUFA[15], BUFB[15];

int main(){
	int i, j, k;
	int a, b;
	while(scanf("%s%s", BUFA, BUFB) == 2){
		i = strlen(BUFA);
		j = strlen(BUFB);
		a = b = 0;
		for(k = 0; k != i; ++k){
			if(BUFA[k] == ',') continue;
			if(isdigit(BUFA[k])){
				a = a * 10 + (BUFA[k] - '0');
				continue;
			}
		}
		if(BUFA[0] == '-') a = -a;		
		for(k = 0; k != j; ++k){
			if(BUFB[k] == ',') continue;
			if(isdigit(BUFB[k])){
				b = b * 10 + (BUFB[k] - '0');
				continue;
			}
			b = -b;
		}
		if(BUFB[0] == '-') b = -b;
		printf("%d\n", a + b);
	}
	return 0;
}