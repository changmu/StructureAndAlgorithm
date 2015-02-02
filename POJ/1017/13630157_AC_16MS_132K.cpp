#include <stdio.h>
#include <string.h>

int main() {
    int a, b, c, d, e, f, ans, tmp;
    const int sam[] = {0, 5, 3, 1};
    while(scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f), a|b|c|d|e|f) {
        ans = f + e + d + (c + 3) / 4;
        tmp = d * 5 + sam[c % 4];
        if(b > tmp) ans += (b - tmp + 8) / 9;
        tmp = ans * 36 - f * 36 - e * 25 - d * 16 - c * 9 - b * 4;
        if(a > tmp) ans += (a - tmp + 35) / 36;
        printf("%d\n", ans);
    }
    return 0;
}