#include <stdio.h>
#include <algorithm>
using namespace std;

#define maxn 1010

int arr[maxn];

int main() {
	int R, N, i, ans, pos;
	while(scanf("%d%d", &R, &N), N > 0) {
		for(i = 0; i < N; ++i)
			scanf("%d", &arr[i]);
		sort(arr, arr + N);
		N = unique(arr, arr + N) - arr;
		ans = pos = i = 0;
		while(i < N) {
			pos = arr[i++]; // 最左未覆盖点
			while(i < N && arr[i] - pos <= R) ++i;
			pos = arr[i-1]; ++ans; // 选择该点
			while(i < N && arr[i] - pos <= R) ++i;
		}
		printf("%d\n", ans);
	}
	return 0;
}