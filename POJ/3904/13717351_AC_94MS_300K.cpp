#include <stdio.h>
#include <string.h>

#define maxn 10010
typedef long long LL;

int p[12], k, que[maxn], back, cnt[maxn], num[maxn], tmp[maxn];
LL Cnm[maxn], sum;

void getp(int n) {
    int i, j, t = n; k = 0;
    for (i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            p[k++] = i;
            while (n % i == 0) 
                n /= i;
        }
    }
    if (n > 1) p[k++] = n;
    back = 0;
    tmp[back] = 0;
    que[back++] = 1;
    for (i = 0, n = t; i < k; ++i) {
        t = back;
        for (j = 0; j < t; ++j) {
            que[back] = p[i] * que[j];
            ++cnt[que[back]];
            tmp[back] = 1 + tmp[j];
            num[que[back]] = tmp[back];
            ++back;
        }
    }
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int N, i, m; Cnm[4] = 1;
    for (i = 5; i < maxn; ++i)
        Cnm[i] = Cnm[i-1] * i / (i - 4);
    while (scanf("%d", &N) == 1) {
        memset(cnt, 0, sizeof(cnt));
        for (i = 0; i < N; ++i) {
            scanf("%d", &m);
            getp(m);
        }
        sum = 0LL;
        for (i = 2; i < maxn; ++i)
            if (cnt[i] >= 4)
                if (num[i] & 1) sum += Cnm[cnt[i]];
                else sum -= Cnm[cnt[i]];
        printf("%lld\n", Cnm[N] - sum);
    }
    return 0;
}