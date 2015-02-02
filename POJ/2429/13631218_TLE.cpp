#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long long LL;

LL gcd(LL a, LL b) {
    return b ? gcd(b, b % a) : a;
}

int main() {
    LL a, b, c, i;
    while(scanf("%lld%lld", &a, &b) == 2) {
        c = b / a;
        for(i = (LL)sqrt((double)c); i > 0; --i)
            if(c % i == 0 && gcd(i, c / i) == 1) {
                printf("%lld %lld\n", i * a, (c / i) * a);
                break;
            }
    }
    return 0;
}