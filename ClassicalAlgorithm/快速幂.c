#include <stdio.h>
#include <string.h>

int square(int x) { return x * x; }

int fast_expt(int x, int n) {
    if (n == 0) return 1;
    if (n & 1) return x * fast_expt(x, n - 1);
    else return square(fast_expt(x, n >> 1));
}

int main() {
    printf("%d\n", fast_expt(2, 3));
    return 0;
}
