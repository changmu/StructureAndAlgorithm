/************************************************************* 
 * 原理: 被除数和除数的最大公约数 == 除数和余数的最大公约数
 *************************************************************/ 
#include <stdio.h>
#include <string.h>

int GCD(int m, int n) {
    if (n == 0) return m;
    else return GCD(n, m % n);
}

int main() {
    printf("%d\n", GCD(18, 27));
    return 0;
}
