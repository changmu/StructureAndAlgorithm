#include <stdio.h>
#include <string.h>
#include <algorithm>

#define maxn 100010

int S[maxn], N, K;

int main() {
    int i, T, cnt, sum, s, t;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &N, &K);
        for(i = 0; i < N; ++i) 
            scanf("%d", &S[i]);
        cnt = N + 1; 
        sum = s = t = 0;
        for(i = 0; i < N; ++i) {
            sum += S[i];
            while(sum >= K) {
                t = i - s + 1;
                cnt = std::min(cnt, t);
                sum -= S[s++];
            }
        }
        if(cnt > N) cnt = 0;
        printf("%d\n", cnt);
    }
    return 0;
}