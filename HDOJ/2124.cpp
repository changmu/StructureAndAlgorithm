////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-05 15:32:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2124
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
#define maxn 602
using std::sort;

int arr[maxn];

int cmp(int a, int b){
	return a > b;
}

int main()
{
	int tar, n, i, ans, sum, ok;
	while(scanf("%d%d", &tar, &n) == 2){
		for(i = 0; i < n; ++i)
			scanf("%d", &arr[i]);
		sort(arr, arr + n, cmp);
		ans = sum = ok = 0;
		for(i = 0; i < n; ++i){
			++ans;
			sum += arr[i];
			if(sum >= tar){
				ok = 1; break;
			}
		}
		if(ok) printf("%d\n", ans);
		else printf("impossible\n");
	}
	return 0;
}