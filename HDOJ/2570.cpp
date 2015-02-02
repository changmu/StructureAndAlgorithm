////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-05 16:54:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2570
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 102
using std::sort;

int arr[maxn];

int main()
{
	int t, n, v, w, i, count, tmp, ans;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &v, &w);
		for(i = 0; i < n; ++i)
			scanf("%d", &arr[i]);
		sort(arr, arr + n);
		count = tmp = ans = 0;
		for(i = 0; i < n; ++i){
			tmp += arr[i];
			if(tmp > w * (i + 1)) break;
			++count; ans = tmp;
		}
		if(!count) printf("0 0.00\n");
		else printf("%d %.2lf\n", count * v, ans * 0.01 / count);
	}
	return 0;
}