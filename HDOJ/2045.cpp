////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-27 22:45:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2045
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
__int64 a[51] = {0, 3, 6, 6};

int main(){
	int n;
	for(int i = 4; i != 51; ++i)
		a[i] = a[i - 1] + a[i - 2] * 2;
	while(scanf("%d", &n) == 1)
		printf("%I64d\n", a[n]);	
	return 0;
}