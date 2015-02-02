////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-29 17:49:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5122
////Problem Title: 
////Run result: Accept
////Run time:546MS
////Run memory:4140KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 1000002

int T[maxn], n;

int lowBit(int x) { return x & -x; }

void add(int v) {
	for(int pos = v; pos <= n; pos += lowBit(pos))
		++T[pos];
}

int getSum(int v) {
	int sum = 0, i;
	for(i = v; i > 0; i -= lowBit(i))
		sum += T[i];
	return sum;
}

int main() {
	int t, i, ans, v;
	scanf("%d", &t);
	for(int cas = 1; cas <= t; ++cas) {
		scanf("%d", &n);
		memset(T, 0, sizeof(int) * (n + 1));
		for(i = ans = 0; i < n; ++i) {
			scanf("%d", &v);
			add(v);
			if(getSum(v) != v) ++ans;
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}