////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-04 17:57:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1049
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
	int n, u, d, ans, sum;
	while(scanf("%d%d%d", &n, &u, &d), n || u || d){
		ans = sum = 0;
		while(sum < n){
			sum += u;
			++ans;
			if(sum >= n) break;
			sum -= d;
			++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}