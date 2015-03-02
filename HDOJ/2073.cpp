////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-18 18:44:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2073
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1068KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>

double cnt_b2t[210];

double f(int x, int y) {
	int a = x + y;
	if (!a) return 0.0;
	return cnt_b2t[a-1] + (a * (a - 1) / 2 + x) * sqrt(2.0);
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int T, x1, y1, x2, y2, i;
	for (i = cnt_b2t[0] = 1; i <= 200; ++i) {
		cnt_b2t[i] = cnt_b2t[i-1] + sqrt(i*i + (i+1)*(i+1)); 
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%.3lf\n", fabs(f(x1, y1) - f(x2, y2)));
	}
	return 0;
}
