#include <stdio.h>
#include <string.h>

typedef __int64 LL;
const LL inf = 0x7ffffffffffffff;
int p[12], k, que[1025], back;

void getp(int n) {
    int i, j, t; k = 0;
    for (i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            p[k++] = i;
            while (n % i == 0) n /= i;
        }
    if (n > 1) p[k++] = n;
    back = 0;
    que[back++] = -1;
    for (i = 0; i < k; ++i) {
        t = back;
        for (j = 0; j < t; ++j)
            que[back++] = p[i] * que[j] * -1;
    }
}

LL nop(LL m) {
    LL sum = 0;
    int i;
    for (i = 1; i < back; ++i)
        sum += m / que[i];
    return sum;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int M, K, ans, i;
    LL L, R, mid;
    while (scanf("%d%d", &M, &K) == 2) {
        getp(M);
        L = 0; R = inf;
        while (L < R - 1) {
            mid = L + R >> 1;
            if(mid - nop(mid) >= K) R = mid;
            else L = mid;
        }
        printf("%I64d\n", R);
    }
    return 0;
}