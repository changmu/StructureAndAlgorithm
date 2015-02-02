////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-06 16:35:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1556
////Problem Title: 
////Run result: Accept
////Run time:593MS
////Run memory:596KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 100000 + 2

int arr[maxn];

int main()
{
	int n, a, b;
	while(scanf("%d", &n), n){
		memset(arr, 0, sizeof(arr));
		
		for(int i = 0; i < n; ++i){
			scanf("%d%d", &a, &b);
			++arr[a]; --arr[b + 1];
		}
		
		for(int i = 1, ans = 0; i <= n; ++i){
			ans += arr[i];
			
			if(i != n) printf("%d ", ans);
			else printf("%d\n", ans);
		}		
	}
	return 0;
}