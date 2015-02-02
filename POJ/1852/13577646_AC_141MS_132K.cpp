#include <stdio.h>

int Min(int a, int b) {
	return a < b ? a : b;
}

int Max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int t, n, i, dis, len, min, max;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &len, &n);
		min = max = 0;
		while(n--) {
			scanf("%d", &dis);
			min = Max(min, Min(dis, len - dis));
			max = Max(max, Max(dis, len - dis));
		}
		printf("%d %d\n", min, max);
	}
	return 0;
}