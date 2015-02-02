#include <stdio.h>
#include <string.h>

#define maxn 50010

int pre[maxn]; // -2 eat -3, -3 eat -4, -4 eat -2

int ufind(int k) {
	int a = k, b;
	while(pre[k] >= 0) k = pre[k];
	while(a != k) {
		b = pre[a];
		pre[a] = k;
		a = b;
	}
	return k;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
	int n, k, i, d, cnt, x, y, a, b;
	while(scanf("%d%d", &n, &k) == 2) {
		cnt = 0;
		memset(pre, -1, sizeof(int) * (n + 1));

		while(k--) {
			scanf("%d%d%d", &d, &x, &y);
			if(x < 1 || y < 1 || x > n || y > n) {
				++cnt; continue;
			}
			a = ufind(x);
			b = ufind(y);

			if(1 == d) {				
				if(pre[a] != pre[b]) {
					if(pre[a] == -1) {
						pre[a] = b;
					} else if(pre[b] == -1) {
						pre[b] = a;
					} else {
						++cnt; continue;
					}
				} else if(a != b) pre[a] = b;
			} else {
                if(a == b) {
                    ++cnt; continue;
                }
                
				if(pre[a] == -1 && pre[b] == -1) {
					pre[a] = -2; pre[b] = -3;
				} else if(pre[a] != -1 && pre[b] == -1) {
					pre[b] = pre[a] - 1;
					if(pre[b] == -5) pre[b] = -2;
				} else if(pre[a] == -1 && pre[b] != -1) {
					pre[a] = pre[b] + 1;
					if(pre[a] == -1) pre[a] = -4;
				} else if(pre[a] != -1 && pre[b] != -1) {
					if(pre[a] == -2 && pre[b] != -3 || 
					   pre[a] == -3 && pre[b] != -4 ||
                       pre[a] == -4 && pre[b] != -2) {
                        ++cnt; continue;
                    }
				}
			}
		}
        printf("%d\n", cnt);
	}
	return 0;
}