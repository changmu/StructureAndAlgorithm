////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-12 17:07:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2665
////Problem Title: 
////Run result: Accept
////Run time:4593MS
////Run memory:15608KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

#define maxn 100005
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

vector<int> T[maxn << 2];
int N, Q;

void build(int l, int r, int rt) {
    if(l == r) {
        int val;
        scanf("%d", &val);
        T[rt].clear();
        T[rt].push_back(val);
        return;
    }

    int mid = (l + r) >> 1;

    build(lson);
    build(rson);

    T[rt].resize(r - l + 1); // Attention
    merge(T[rt<<1].begin(), T[rt<<1].end(), T[rt<<1|1].begin(), T[rt<<1|1].end(), T[rt].begin());
}

int query(int L, int R, int val, int l, int r, int rt) {
    if(L == l && R == r) {
        return upper_bound(T[rt].begin(), T[rt].end(), val) - T[rt].begin();
    }

    int mid = (l + r) >> 1;

    if(R <= mid) return query(L, R, val, lson);
    else if(L > mid) return query(L, R, val, rson);
    return query(L, mid, val, lson) + query(mid + 1, R, val, rson);
}

int main() {
    int a, b, c, k, left, right, mid, t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &N, &Q);
        build(1, N, 1);
        while(Q--) {
            scanf("%d%d%d", &a, &b, &k);
            left = -1; right = N - 1;
            while(right - left > 1) { // binary search
                mid = (left + right) >> 1;
                c = query(a, b, T[1][mid], 1, N, 1);
                if(c >= k) right = mid;
                else left = mid;
            }
            printf("%d\n", T[1][right]);
        }
    }
    return 0;
}