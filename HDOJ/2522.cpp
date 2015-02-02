////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-09 18:28:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2522
////Problem Title: 
////Run result: Accept
////Run time:453MS
////Run memory:336KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 100002

bool vis[maxn];

int main()
{
	int t, n, m;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n == 1){
			printf("1\n"); continue;
		}
		memset(vis, 0, sizeof(vis));
		if(n < 0){
			putchar('-'); n = -n;
		}
		printf("0.");
		m = 1; vis[0] = 1;
		while(!vis[m]){
			vis[m] = 1; m *= 10; 
			printf("%d", m / n);
			m %= n;
		}
		printf("\n");
	}
	return 0;
}