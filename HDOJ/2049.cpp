////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-28 21:48:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2049
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int t, i, n, m;
	__int64 s, x, a[21] = {0, 0, 1};
	for(i = 3; i != 21; ++i)
		a[i] = (i - 1) * (a[i-1] + a[i-2]);
	scanf("%d", &t);
	while(t-- && scanf("%d%d", &n, &m)){
		s = x = 1;
		for(i = 1; i <= m; ++i, --n) s *= n;
		for(i = m; i > 1; --i) x *= i;
		printf("%I64d\n", s / x * a[m]);		
	}
	return 0;
}