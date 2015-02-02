#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

#define maxn 102

double arr[maxn], ans;

double cal(double a, double b) {
    return 2.0 * sqrt(a * b);
}

int main() {
    int i, j, n;
    scanf("%d", &n);
    for(i = 0; i < n; ++i)
        scanf("%lf", &arr[i]);
    std::sort(arr, arr + n);
    ans = arr[--n];
    while(n) ans = cal(ans, arr[--n]);
    printf("%.3lf\n", ans);
    return 0;
}