////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2015-02-03 11:23:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2607
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:1284KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 100002

int X[maxn], Y[maxn], Z[maxn];
char buf[40];

int main() {
	// freopen("data.in", "r", stdin); 
	int i, id = 0, cnt = 0, ret = 0; // id记录数据块中条数, ret记录最终结果
	while (gets(buf)) {
		if (*buf == NULL) {
			if (id)
				if (ret == 0) puts("None.");
				else {
					while (id--) {
						if (ret >= X[id] && ret <= Y[id] && (ret - X[id]) % Z[id] == 0)
							++cnt;
					}
					printf("%d %d\n", ret, cnt);
				}
			id = cnt = ret = 0;
			continue;
		}

		sscanf(buf, "%d%d%d", &X[id], &Y[id], &Z[id]);
		for (i = X[id]; i <= Y[id]; i += Z[id])
			ret ^= i;
		++id;
	}
	if (id) 
		if (ret == 0) puts("None.");
		else {
			while (id--) {
				if (ret >= X[id] && ret <= Y[id] && (ret - X[id]) % Z[id] == 0)
					++cnt;
			}
			printf("%d %d\n", ret, cnt);
		}
	return 0;
}
