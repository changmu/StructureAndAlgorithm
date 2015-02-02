////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-09-22 21:21:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5023
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:16676KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 1000002
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

struct Node {
    int col;
    bool lazy;
} T[maxn << 2];

void pushDown(int rt) {
    T[rt].lazy = false;
    T[rt << 1].lazy = T[rt << 1 | 1].lazy = true;
    T[rt << 1].col = T[rt << 1 | 1].col = T[rt].col;
}

void pushUp(int rt) {
    T[rt].col = T[rt << 1].col | T[rt << 1 | 1].col;
}

void build(int l, int r, int rt) {
    T[rt].col = 4; // 1 << 2;
    T[rt].lazy = false;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
}

void update(int L, int R, int col, int l, int r, int rt) {
    if(L == l && R == r) {
        T[rt].lazy = true;
        T[rt].col = 1 << col;
        return;
    }
    if(T[rt].lazy) pushDown(rt);
    int mid = (l + r) >> 1;
    if(R <= mid) update(L, R, col, lson);
    else if(L > mid) update(L, R, col, rson);
    else {
        update(L, mid, col, lson);
        update(mid + 1, R, col, rson);
    }
    pushUp(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L == l && R == r) {
        return T[rt].col;
    }
    if(T[rt].lazy) pushDown(rt);
    int mid = (l + r) >> 1, ans;
    if(R <= mid) ans = query(L, R, lson);
    else if(L > mid) ans = query(L, R, rson);
    else {
        ans = query(L, mid, lson) | query(mid + 1, R, rson);
    }
    return ans;
}

int main() {
    //freopen("stdin.txt", "r", stdin);
    int n, m, a, b, c, i, ans;
    char ch[2];
    while(scanf("%d%d", &n, &m) != EOF && (n || m)) {
        build(1, n, 1);
        while(m--) {
            scanf("%s%d%d", ch, &a, &b);
            if(ch[0] == 'P') {
                scanf("%d", &c);
                update(a, b, c, 1, n, 1);
            } else {
                ans = query(a, b, 1, n, 1);
                for(i = 0; i <= 30; ++i)
                    if((ans >> i) & 1) {
                        printf("%d", i);
                        break;
                    }
                for(++i; i <= 30; ++i)
                    if((ans >> i) & 1)
                        printf(" %d", i);
                printf("\n");
            }
        }
    }    
    return 0;
}
