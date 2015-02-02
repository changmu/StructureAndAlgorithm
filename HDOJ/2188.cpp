////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-13 19:10:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2188
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
	int t, n, m;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		if(n % (m + 1)) printf("Grass\n");
		else printf("Rabbit\n");
	}
	return 0;
}