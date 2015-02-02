////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-31 16:02:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2099
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

int main()
{
	int a, b, i, sign;
	while(scanf("%d%d", &a, &b), a || b){
		a *= 100; sign = 0;
		for(i = 0; i < 100; ++i)
			if((a + i) % b == 0){
				if(sign) printf(" %02d", i);
				else printf("%02d", i);
				sign = 1;
			}
		printf("\n");
	}
	return 0;
}