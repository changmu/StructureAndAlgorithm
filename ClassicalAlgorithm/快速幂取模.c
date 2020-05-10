#include <stdio.h>
#include <string.h>

int square(int x) { return x * x; }

int fast_expt_mod(int x, int n, int mod) {
    if (n == 0) return 1;

    if (n & 1) 
        return (x * fast_expt_mod(x, n - 1, mod)) % mod;
    else 
        return square(fast_expt_mod(x, n >> 1, mod)) % mod;
}

int main() {
    printf("%d\n", fast_expt_mod(2, 3, 5));
    return 0;
}
