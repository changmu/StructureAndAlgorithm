// POJ3253
#include <stdio.h>
#include <string.h>

#define maxn 20010
typedef long long LL;

int L[maxn];

void swap(int &a, int &b) {
	int t = a; a = b; b = t;
}

int main() {
	int n, i, min1, min2;
	LL sum, tmp;
	while(scanf("%d", &n) == 1) {
		for(i = 0; i < n; ++i)
			scanf("%d", &L[i]);
		sum = 0;
		while(n > 1) {
			min1 = 0; min2 = 1; // 最短和次短
			if(L[min1] > L[min2]) swap(min1, min2);
			for(i = 2; i < n; ++i) {
				if(L[i] < L[min1]) {
					min2 = min1;
					min1 = i;
				} else if(L[i] < L[min2]) {
					min2 = i;
				}
			}
			tmp = L[min1] + L[min2];
			sum += tmp;
			if(min1 == n - 1) swap(min1, min2);
			L[min1] = tmp;
			L[min2] = L[--n];
		}
		printf("%lld\n", sum);
	}
	return 0;
}
