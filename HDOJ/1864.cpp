////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-23 13:09:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1864
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>

struct Node {
	double p[26];
	double total;
} arr[32];
int N;

bool cmp(Node a, Node b) {
	return a.total > b.total;
}

int main() {
	double maxP, ans, tmp;
	char ch;
	int i, j, m, ok;
	while(scanf("%lf%d", &maxP, &N), N) {
		ans = 0;
		for(i = 0; i < N; ++i) {
			for(j = 0; j < 26; ++j)
				arr[i].p[j] = 0;
			arr[i].total = 0;
			scanf("%d", &m);
			ok = 1;
			while(m--) {
				scanf("%*c%c:%lf", &ch, &tmp);
				arr[i].p[ch-'A'] += tmp;
				arr[i].total += tmp;
				if(arr[i].p[ch-'A'] > 600 || ch > 'C')
					ok = 0;
			}
			if(!ok || arr[i].total > 1000) {
				--i; --N;
			}
			/*if(arr[i].total > maxP) {
				ans += maxP;
				maxP = 0;
			} else {
				ans += arr[i].total;
				maxP -= arr[i].total;
			}*/
		}
		std::sort(arr, arr + N, cmp);
		for(i = 0; i < N; ++i)
			if(arr[i].total <= maxP) {
				ans += arr[i].total;
				maxP -= arr[i].total;
			}
		printf("%.2lf\n", ans);
	}
	return 0;
}
