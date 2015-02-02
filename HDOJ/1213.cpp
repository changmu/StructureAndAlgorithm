////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-06 18:15:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1213
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 1002

int pre[maxn];

int unionFind(int a)
{
	int b = a;
	while(pre[a] != -1) a = pre[a];
	int k;
	while(b != a){
		k = pre[b];
		pre[b] = a;
		b = k;
	}
	return a;
}

int main()
{
	int n, m, t, a, b, ans;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		memset(pre, -1, sizeof(pre));
		ans = n;
		while(m--){
			scanf("%d%d", &a, &b);
			a = unionFind(a);
			b = unionFind(b);
			if(a != b){
				--ans; pre[a] = b;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}