#include <stdio.h>
#include <string.h>

#define maxn 5010

int cow[maxn], N, K, M; // 奶牛们的初始位置,0前1后
int tra[maxn]; // 是否翻转第i头牛,1翻

int cal(int k) { // 翻转顺序从左往右
    int ans = 0, i, sum = 0;
    for(i = 0; i + k <= N; ++i) {
        tra[i] = 0; // initialize
        if((sum + cow[i]) & 1) {
            tra[i] = 1; 
            ++ans;
        }
        sum += tra[i]; // 尺取法
        if(i - k + 1 >= 0)
            sum -= tra[i-k+1];
    }
    // 检查剩下的是否有反向奶牛
    for( ; i < N; ++i)
        if((sum + cow[i]) & 1)
            return -1;
        else if(i - k + 1 >= 0)
            sum -= tra[i-k+1];
    return ans;
}

int main() {
    char ch[2];
    int i, m, k;
    while(scanf("%d", &N) == 1) {
        for(i = 0; i < N; ++i) {
            scanf("%s", ch);
            if(ch[0] == 'B') cow[i] = 1;
            else cow[i] = 0;
        }
        M = N; K = 1;
        for(k = 1; k <= N; ++k) {
            m = cal(k);
            if(m >= 0 && m < M) {
                M = m; K = k;
            }
        }
        printf("%d %d\n", K, M);
    }
    return 0;
}