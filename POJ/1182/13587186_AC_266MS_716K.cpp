#include <stdio.h>
#include <string.h>

#define maxn 150010

int pre[maxn];

int ufind(int k) {
	int a = k, b;
	while(pre[k]) k = pre[k];
	while(a != k) {
		b = pre[a];
		pre[a] = k;
		a = b;
	}
	return k;
}

bool same(int a, int b) {
	return ufind(a) == ufind(b);
}

void unite(int a, int b) {
	a = ufind(a);
	b = ufind(b);
	if(a == b) return;
	else pre[b] =  a;
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int n, k, i, d, x, y, ans = 0;
	scanf("%d%d", &n, &k);
	while(k--) {
		scanf("%d%d%d", &d, &x, &y);

		if(x < 1 || x > n || y < 1 || y > n) {
			++ans; continue;
		}

		if(1 == d) {
			// x eats y or y eats x
			if(same(x, y + n) || same(x, y + 2*n)) {
				++ans; continue;
			}
			unite(x, y);
			unite(x + n, y + n);
			unite(x + 2*n, y + 2*n);
		} else {
			// x ans y is same or y eats x
			if(same(x, y) || same(x, y + 2*n)) {
				++ans; continue;
			}
			unite(x, y + n);
			unite(x + n, y + 2*n);
			unite(x + 2*n, y);
		}
	}
	printf("%d\n", ans);
	return 0;
}
