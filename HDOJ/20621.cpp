////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-19 09:16:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2062
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:1068KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>

__int64 an[22] = {0, 1}, m;
int box[22], vis[22];

int find_m_min(int n, int m) {
	int i, k = 0;
	for (i = 1; i <= n; ++i)
		if (!vis[i] && ++k == m) {
			break;
		} 
	vis[i] = 1; return i;
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int i, n, id, j, nn, tmp;
	for (i = 2; i <= 20; ++i)
		an[i] = i * (an[i-1] + 1);
	while (scanf("%d%I64d", &n, &m) == 2) {
		memset(vis, 0, sizeof(vis));
		nn = n;
		while (n-- && m) {
			j = m / (an[n] + 1) + (m % (an[n] + 1) ? 1 : 0);
			printf("%d", find_m_min(nn, j));
			m -= (j - 1) * (an[n] + 1) + 1;
			printf("%c", m ? ' ' : '\n');
		}
	}
	return 0;
}
