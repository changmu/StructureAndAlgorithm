////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-24 08:15:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1116
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:284KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 28

int pre[maxn], vis[maxn], in[maxn], out[maxn];
char str[1002];

int abs(int k) { return k < 0 ? -k : k; }

int ufind(int k) {
	int a = k, b;
	while(pre[k] != -1) k = pre[k];
	while(a != k) {
		b = pre[a];
		pre[a] = k;
		a = b;
	}
	return k;
}

bool unite(int a, int b) {
	a = ufind(a);
	b = ufind(b);
	if(a == b) return false;
	else {
		pre[a] = b;
		return true;
	}
}

int main() {
	int T, N, i, j, flag1, flag2, cnt, a, b;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		memset(pre, -1, sizeof(pre));
		memset(vis, 0, sizeof(vis));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		cnt = flag1 = flag2 = 0;
		while(N--) {
			scanf("%s", str);
			a = *str - 'a';
			b = str[strlen(str)-1] - 'a';
			if(!vis[a]) {
				vis[a] = 1; ++cnt;
			}
			if(!vis[b]) {
				vis[b] = 1; ++cnt;
			}
			++out[a]; ++in[b];
			if(unite(a, b)) --cnt;
		}
		if(cnt != 1) { // É­ÁÖ
			printf("The door cannot be opened.\n");
		} else {
			for(i = 0; i < 26; ++i) {
				if(in[i] + 1 == out[i])
					++flag1;
				else if(out[i] + 1 == in[i])
					++flag2;
				else if(abs(in[i] - out[i]) > 1)
					break;
			}
			if(i < 26) printf("The door cannot be opened.\n");
			else if(!flag1 && !flag2 || flag1 == 1 && flag2 == 1)
				printf("Ordering is possible.\n");
		}
	}
	return 0;
}