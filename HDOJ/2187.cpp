////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-05 15:52:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2187
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
#define maxn 1002
using std::sort;

struct Node{
	int v, w;
} arr[maxn];

bool cmp(Node a, Node b){
	return a.v < b.v;
}

int main()
{
	int t, v, n, i;
	double ans;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &v, &n);
		for(i = 0; i < n; ++i)
			scanf("%d%d", &arr[i].v, &arr[i].w);
		sort(arr, arr + n, cmp);
		for(i = 0, ans = 0; i < n; ++i){
			if(v >= arr[i].v * arr[i].w){
				ans += arr[i].w;
				v -= arr[i].v * arr[i].w;
			}else{
				ans += v * 1.0 / arr[i].v;
				break;
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}