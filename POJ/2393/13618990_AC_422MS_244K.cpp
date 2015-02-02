#include <stdio.h>
#include <string.h>

#define maxn 10002

int min(int a, int b) {
    return a < b ? a : b;
}

int X[maxn], Y[maxn];

int main() {
    int N, S, i, j;
    __int64 sum;
    while(scanf("%d%d", &N, &S) == 2) {
        for(i = 0; i < N; ++i)
            scanf("%d%d", &X[i], &Y[i]);
        for(i = sum = 0; i < N; ++i) {
            sum += X[i] * Y[i];
            for(j = i + 1; j < N; ++j)
                X[j] = min(X[j], X[i] + S * (j - i));
        }
        printf("%I64d\n", sum);
    }
    return 0;
}