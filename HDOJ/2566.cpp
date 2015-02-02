////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-08 21:48:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2566
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
	int n, m, x, y, cnt, t, tmp, i;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		tmp = 5 * n - m;
		for(i = cnt = 0; i <= n; ++i)
			for(int j = 0; j <= n; ++j)
				if(4*i+3*j==tmp && i+j<=n)
					++cnt;
		printf("%d\n", cnt);
	}
	return 0;
}