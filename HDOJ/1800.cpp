////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-05 11:56:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1800
////Problem Title: 
////Run result: Accept
////Run time:453MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 3002
using std::sort;

int arr[maxn];
bool vis[maxn];

bool cmp(int a, int b){
	return a > b;
}

int main()
{
	int n, i, j, tmp, ans;
	while(scanf("%d", &n) == 1){
		for(i = 0; i < n; ++i)
			scanf("%d", arr + i);
		sort(arr, arr + n, cmp);
		memset(vis, 0, sizeof(vis));
		for(i = 0, ans = n; i < n; ++i){
			if(vis[i]) continue;
			tmp = arr[i];
			for(j = i + 1; j < n; ++j){
				if(vis[j]) continue;
				if(tmp > arr[j]){
					tmp = arr[j]; --ans;
					vis[j] = 1;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}