#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long long LL;

bool isPrime(int n) {
    if(n < 2) return false;
    int t = sqrt((double)n);
    for(int i = 2; i <= t; ++i)
        if(n % i == 0) return false;
    return true;
}

LL mod_power(LL x, LL n, LL mod) {
    LL ret = 1;
    for( ; n > 0; n >>= 1) {
        if(n & 1) ret = ret * x % mod;
        x = x * x % mod;
    }
    return ret;
}

int main() {
    LL p, a;
    while(scanf("%lld%lld", &p, &a), p | a) {
        if(isPrime(p)) printf("no\n");
        else printf(mod_power(a, p, p) == a ? "yes\n" : "no\n");
    }
    return 0;
}