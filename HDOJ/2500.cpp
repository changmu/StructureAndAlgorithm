////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-26 21:01:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2500
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>

void PRINT(int m)
{
	while(m--) printf("HDU");
	printf("\n");
}

int main()
{
	int n, m, times;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &m);
		times = m * 3;
		while(times--) PRINT(m);
	}
	return 0;
}