#include <stdio.h>
#include <string.h>

#define maxn 10010
typedef long long LL;

LL k, cnt[maxn], num[maxn];
LL Cnm[maxn], sum;

void getp(LL n) {
    LL i, j, t = n; k = 0;
    for (i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ++k;
            ++cnt[i];
            while (n % i == 0) 
                n /= i;
        }
    }
    if (n > 1) {
        ++k;
        ++cnt[n];
    }
    num[t] = k;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    LL N, i, m; Cnm[4] = 1;
    for (i = 5; i < maxn; ++i)
        Cnm[i] = Cnm[i-1] * i / (i - 4);
    while (scanf("%lld", &N) == 1) {
        memset(cnt, 0, sizeof(cnt));
        for (i = 0; i < N; ++i) {
            scanf("%lld", &m);
            getp(m);
        }
        sum = 0;
        for (i = 2; i < maxn; ++i)
            if (cnt[i] >= 4)
                if (num[i] & 1) sum += Cnm[cnt[i]];
                else sum -= Cnm[cnt[i]];
        printf("%lld\n", Cnm[N] - sum);
    }
    return 0;
}