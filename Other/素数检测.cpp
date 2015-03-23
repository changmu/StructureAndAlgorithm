/************************************************************* 
 * 原理: 如果n不是素数，它必然有一个小于等于sqrt(n)的因子
 *************************************************************/ 
#include <stdio.h>
#include <string.h>
#include <math.h>

bool isPrime(int n) {
    if (n < 2) return false;
    int k = (int) sqrt(n);
    for (int i = 2; i <= k; ++i)
        if (n % i == 0) return false;
    return true;
}

int main() {
    printf("%d: %s\n", 1234567, isPrime(1234567) ? "Yes" : "No");
    return 0;
}
