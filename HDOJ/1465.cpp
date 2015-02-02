////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-03-15 18:18:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1465
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
__int64 a[21] = {0, 0, 1, 2};

int main(){
	int i;
	for(i = 4; i != 21; ++i)
		a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
	while(scanf("%d", &i) == 1)
		printf("%I64d\n", a[i]);
	return 0;
}