#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

#define maxn 10010

struct Node {
	int pos, val;
	friend bool operator<(Node a, Node b) {
		return a.val < b.val;
	}
} A[maxn];

bool cmp(Node a, Node b) {
	return a.pos > b.pos;
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int N, L, P, i, dis, cnt;
	while(scanf("%d", &N) == 1) {
		for(i = 0; i < N; ++i)
			scanf("%d%d", &A[i].pos, &A[i].val);
		scanf("%d%d", &L, &P);
		std::sort(A, A + N, cmp);

		std::priority_queue<Node> pq;
		dis = P;
		cnt = 0;

		for(i = 0; i < N; ++i) {
			if(L - A[i].pos <= dis) {
				pq.push(A[i]);
			} else if(!pq.empty()) {
				dis += pq.top().val;
				pq.pop(); ++cnt; --i;
				if(dis >= L) break;
			} else break;
		}

		if(dis < L) cnt = -1;
		printf("%d\n", cnt);
	}
	return 0;
}
