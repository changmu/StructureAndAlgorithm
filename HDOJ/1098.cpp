////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-21 16:24:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1098
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main() {
	int k, a;
	while(~scanf("%d", &k)) {
		for(a = 0; a <= 65; ++a)
			if((18 + k*a) % 65 == 0) {
				printf("%d\n", a);
				break;
			}
		if(a > 65) printf("no\n");
	}
	return 0;
}