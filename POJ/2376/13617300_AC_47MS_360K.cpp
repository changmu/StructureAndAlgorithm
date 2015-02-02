#include <stdio.h>
#include <string.h>
#include <algorithm>

#define maxn 25005

struct Node {
	int u, v;
} E[maxn];

bool cmp(Node a, Node b) {
	return a.u < b.u;
}

int main() {
	int N, T, flag, ans, right, i;
	while(scanf("%d%d", &N, &T) == 2) {
		for(i = 0; i < N; ++i)
			scanf("%d%d", &E[i].u, &E[i].v);
		std::sort(E, E + N, cmp);
		ans = right = 0;
		flag = 1;
		i = 0;
		while(flag <= T) {
			for( ; i < N && E[i].u <= flag; ++i)
				if(E[i].u <= flag && E[i].v > right)
					right = E[i].v;
			if(right >= flag) flag = right + 1, ++ans;
			else break;
		}
		if(flag <= T) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}
