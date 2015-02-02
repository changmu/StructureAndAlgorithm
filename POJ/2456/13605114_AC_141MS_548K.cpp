#include <stdio.h>
#include <string.h>
#include <algorithm>

#define maxn 100010

int pos[maxn], N, C;

bool cal(int k) {
    int i, m, cnt = 0, s, t;
    s = 0;
    for(m = 1; m < C; ++m) {
        t = s + 1;
        while(t < N && pos[t] - pos[s] < k)
            ++t;
        if(t == N) return false;
        s = t;
    }
    return true;
}

int main() {
    int i, left, mid, right;
    while(scanf("%d%d", &N, &C) != EOF) {
        for(i = 0; i < N; ++i)
            scanf("%d", &pos[i]);
        std::sort(pos, pos + N);
        left = 0; right = pos[N - 1];
        while(right - left > 1) {
            mid = (left + right) >> 1;
            if(cal(mid)) left = mid;
            else right = mid;
        }
        printf("%d\n", left);
    }
    return 0;
}