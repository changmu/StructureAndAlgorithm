#include <stdio.h>
#include <string.h>
#include <algorithm>

#define maxn 100010

int S[maxn], N, K;

int main() {
    int i, T, cnt, tmp;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &N, &K);
        for(i = 0; i < N; ++i) {
            scanf("%d", &S[i]);
            if(i) S[i] += S[i - 1];
        }
        if(S[N - 1] < K) {
            printf("0\n");
            continue;
        }
        cnt = N + 1;
        for(i = 0; i < N && S[i] + K <= S[N - 1]; ++i) {
            tmp = std::lower_bound(S + i, S + N, S[i] + K) - S - i;
            cnt = std::min(cnt, tmp);
        }
        printf("%d\n", cnt);
    }
    return 0;
}