#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

const int mod = 1000000;
const int maxn = 1002;
const int maxm = 100002;

int dp[maxm], arr[maxn], c1[maxm], c2[maxm];

int main() {
    int T, A, S, B, i, j, k, v, sum;
    while(scanf("%d%d%d%d", &T, &A, &S, &B) != EOF) {
        memset(arr, 0, sizeof(int) * (T + 1));
        for(i = 0; i < A; ++i) {
            scanf("%d", &v);
            ++arr[v];
        }
        memset(c1, 0, sizeof(int) * (B + 1));
        memset(c2, 0, sizeof(int) * (B + 1));
        c1[0] = 1;
        for(i = 1; i <= T; ++i) {
            for(j = 0; j <= B; ++j)
                for(k = 0; k <= arr[i] && k + j <= B; ++k)
                    c2[j+k] = (c1[j] + c2[j+k]) % mod;
                for(j = 0; j <= B; ++j) {
                    c1[j] = c2[j]; c2[j] = 0;
                }
        }
        for(sum = 0, i = S; i <= B; ++i)
            sum = (sum + c1[i]) % mod;
        printf("%d\n", sum);
    }
    return 0;
}
