////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-05 15:13:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2111
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
#define maxn 102
using std::sort;

struct Node{
	int w, v;
} arr[maxn];

bool cmp(Node a, Node b){
	return a.w > b.w;
}

int main()
{
	int v, n, i, ans;
	while(scanf("%d", &v), v){
		scanf("%d", &n);
		for(i = 0; i < n; ++i)
			scanf("%d%d", &arr[i].w, &arr[i].v);
		sort(arr, arr + n, cmp);
		ans = 0;
		for(i = 0; i < n; ++i)
			if(arr[i].v <= v){
				ans += arr[i].v * arr[i].w;
				v -= arr[i].v;
			}else {
				ans += v * arr[i].w; break;
			}
		printf("%d\n", ans);
	}
	return 0;
}