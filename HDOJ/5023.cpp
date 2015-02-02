////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-09-22 17:57:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5023
////Problem Title: 
////Run result: Accept
////Run time:406MS
////Run memory:18728KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define maxn 100010
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

struct Node {
    int num, col[62];
    bool lazy;
} T[maxn << 2];
int a[maxn], b[maxn], c[maxn], hash[maxn << 1];
bool ans[32];
char op[maxn];

void pushDown(int rt) {
    T[rt << 1].lazy = T[rt << 1 | 1].lazy = true;
    T[rt].lazy = false;
    T[rt << 1].col[0] = T[rt << 1 | 1].col[0] = T[rt].col[0];
    T[rt << 1].num = T[rt << 1 | 1].num = 1;
}

void pushUp(int rt) {
    int count = 0, i;
    for(i = 0; i < T[rt << 1].num; ++i)
        T[rt].col[count++] = T[rt << 1].col[i];
    for(i = 0; i < T[rt << 1 | 1].num; ++i)
        T[rt].col[count++] = T[rt << 1 | 1].col[i];
    sort(T[rt].col, T[rt].col + count);
    T[rt].num = unique(T[rt].col, T[rt].col + count) - T[rt].col;
}

void build(int l, int r, int rt) {
    T[rt].lazy = false;
    T[rt].num = 1;
    T[rt].col[0] = 2;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
}

void update(int L, int R, int val, int l, int r, int rt) {
    if(L == l && R == r) {
        T[rt].lazy = true;
        T[rt].num = 1;
        T[rt].col[0] = val;
        return;
    }
    if(T[rt].lazy) pushDown(rt);
    int mid = (l + r) >> 1;
    if(R <= mid) update(L, R, val, lson);
    else if(L > mid) update(L, R, val, rson);
    else {
        update(L, mid, val, lson);
        update(mid + 1, R, val, rson);
    }
    pushUp(rt);
}

void query(int L, int R, int l, int r, int rt) {
    if(L == l && R == r) {
        for(int i = 0; i < T[rt].num; ++i)
            ans[T[rt].col[i]] = true;
        return;
    }
    if(T[rt].lazy) pushDown(rt);
    int mid = (l + r) >> 1;
    if(R <= mid) query(L, R, lson);
    else if(L > mid) query(L, R, rson);
    else {
        query(L, mid, lson);
        query(mid + 1, R, rson);
    }
}

int main() {
    //freopen("stdin.txt", "r", stdin);
    int n, m, i, id, j;
    char ch[2];
    while(scanf("%d%d", &n, &m) != EOF && (n || m)) {
        for(i = id = 0; i < m; ++i) {
            scanf("%s%d%d", ch, &a[i], &b[i]);
            hash[id++] = a[i];
            hash[id++] = b[i];
            if(ch[0] == 'P') scanf("%d", &c[i]);
            op[i] = ch[0];
        }
        sort(hash, hash + id);
        id = unique(hash, hash + id) - hash;
        build(1, id, 1);
        for(i = 0; i < m; ++i) {
            a[i] = lower_bound(hash, hash + id, a[i]) - hash + 1;
            b[i] = lower_bound(hash, hash + id, b[i]) - hash + 1;
            if(op[i] == 'P') update(a[i], b[i], c[i], 1, id, 1);
            else {
                memset(ans, 0, sizeof(ans));
                query(a[i], b[i], 1, id, 1);
                for(j = 0; j <= 30; ++j)
                    if(ans[j]) {
                        printf("%d", j);
                        break;
                    }
                for(++j; j <= 30; ++j)
                    if(ans[j]) printf(" %d", j);
                printf("\n");
            }
        }
    }
    return 0;
}