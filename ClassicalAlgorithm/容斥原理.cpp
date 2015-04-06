/************************************************************* 
 * 容斥原理：求M、N的第K个与它们俩互质的数。
 * 容斥原理需要获得所有素因子，然后将它们复合起来，这题比较坑的
 * 地方是要先分别求出M、N的素因子，然后排序去重，否则若先求出
 * M、N的最小公倍数后再会超时，比如M和N都是接近1亿的素数，那么
 * LCM就大得逆天了，for循环需要执行近一亿次，但是如果单独求的
 * 话，for循环最多需要执行2 * sqrt(1亿)，两相比较，当然是后者省时
 *************************************************************/ 
#include <stdio.h>
#include <string.h>
#include <algorithm>

typedef __int64 LL;
const LL inf = 1LL << 62;
int M, N, K, back, id;
LL Prime[30], Complex[20000];

void get_prime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i) continue;
        Prime[id++] = i;
        while (n % i == 0)
            n /= i;
    }
    if (n > 1) Prime[id++] = n;
}

void get_divisor_group() {
    int i, j, t;
    id = back = 0;
    
    get_prime(M);
    get_prime(N);

    std::sort(Prime, Prime + id);
    id = std::unique(Prime, Prime + id) - Prime;

    Complex[back++] = -1;
    for (i = 0; i < id; ++i) {
        t = back;
        for (j = 0; j < t; ++j)
            Complex[back++] = Prime[i] * Complex[j] * -1;
    }
}

LL not_coprime(LL num) {
    LL cnt = 0;
    for (int i = 1; i < back; ++i)
        cnt += num / Complex[i];
    return cnt;
}

LL binary_solve() {
    LL L = 1, R = inf, mid, cnt;

    get_divisor_group();

    while (L < R) {     // 找出第一个大于等于K的数
        mid = L + R >> 1;
        if ((cnt = mid - not_coprime(mid)) < K)
            L = mid + 1;
        else R = mid;
    }

    return L;
}

int main() {
    int T, cas, i;

    scanf("%d", &T);
    for (cas = 1; cas <= T; ++cas) {
        scanf("%d%d%d", &M, &N, &K);
        printf("Case %d: %I64d\n", cas, binary_solve());
    }
    return 0;
}
