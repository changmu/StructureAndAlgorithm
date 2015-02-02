////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-05 14:57:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2037
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
#define maxn 102
using std::sort;

struct Node{
	int l, r;
} arr[maxn];

bool cmp(Node a, Node b){
	return a.r < b.r;
}

int main()
{
	int n, i, ans, flag;
	while(scanf("%d", &n), n){
		for(i = 0; i < n; ++i)
			scanf("%d%d", &arr[i].l, &arr[i].r);
		sort(arr, arr + n, cmp);
		flag = arr[0].r; ans = 1;
		for(i = 1; i < n; ++i)
			if(arr[i].l >= flag){
				++ans; flag = arr[i].r;
			}
		printf("%d\n", ans);
	}
	return 0;
}