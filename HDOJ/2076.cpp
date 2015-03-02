////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-18 17:58:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2076
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1048KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	// freopen("stdin.txt", "r", stdin);
	int T, h, m, s, i;
	int hs, ms;
	double H, M;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &h, &m, &s);
		if (h >= 12) h -= 12;
		ms = m * 60 + s;
		hs = h * 3600 + ms;
		H = (double)hs / (12 * 3600) * 360.0;
		M = 360.0 * ms / 3600;
		// printf("%lf %lf..\n", H, M);
		H = fabs(H - M);
		if (H > 180.0) H = 360 - H; 
		printf("%d\n", (int)H);
	}
	return 0;
}
