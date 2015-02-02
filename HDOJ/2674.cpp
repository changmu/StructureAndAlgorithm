////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-05 21:31:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2674
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int arr[42] = {1, 1};

int main()
{
	int i;
	for(i = 2; i < 42; ++i)
		arr[i] = (arr[i-1] * i) % 2009;
	while(scanf("%d", &i) == 1){
		if(i < 42) printf("%d\n", arr[i]);
		else printf("0\n");
	}
	return 0;
}