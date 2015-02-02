#include <cstdio>
#include <cstring>
#include <algorithm>

#define maxn 4010
typedef __int64 LL;
using namespace std;

int A[4][maxn], CD[maxn * maxn];

int main() {
    LL ret = 0;
    int i, j, n, id = 0, tmp;
    scanf("%d", &n);
    for(i = 0; i < n; ++i) {
        for(j = 0; j < 4; ++j)
            scanf("%d", &A[j][i]);
    }
    for(i = 0; i < n; ++i)
        for(j = 0; j < n; ++j)
            CD[id++] = A[2][i] + A[3][j];
    sort(CD, CD + id);

    for(i = 0; i < n; ++i)
        for(j = 0; j < n; ++j) {
            tmp = A[0][i] + A[1][j];
            ret += upper_bound(CD, CD + id, -tmp) - lower_bound(CD, CD + id, -tmp);
        }
    printf("%I64d\n", ret);
}