////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-09-11 19:39:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4981
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
#define maxn 1010
using std::sort;

int arr[maxn];

int main() {
	int n, i;
	double a, sum;
	while(scanf("%d", &n) == 1) {
		for(i = 0, sum = 0.0; i < n; ++i) {
			scanf("%d", arr + i);
			sum += arr[i];
		}
		sort(arr, arr + n);
		sum /= n;
		if((n & 1) == 0) --n;
		a = arr[n >> 1];
		if(sum < a) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}