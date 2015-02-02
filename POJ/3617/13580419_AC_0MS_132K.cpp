#include <stdio.h>
#include <string.h>

#define maxn 2010

char S[maxn];

int main() {
	int n, i, a, b, cnt, left;
	while(scanf("%d", &n) == 1) {
		for(i = 0; i < n; ++i)
			scanf("\n%c", &S[i]);
		cnt = a = 0; b = n - 1;
		while(a <= b) {
			left = 0;
			for(i = 0; a + i <= b; ++i) {
				if(S[a+i] < S[b-i]) {
					left = 1; break;
				} else if(S[a+i] > S[b-i])
					break;
			}
			if(left) putchar(S[a++]);
			else putchar(S[b--]);
			if(++cnt == 80) {
				putchar('\n');
				cnt = 0;
			}
		}
		putchar('\n');
	}
	return 0;
}