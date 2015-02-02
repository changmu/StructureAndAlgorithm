#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 202
#define lson l, mid, rt << 1
#define rson mid, r, rt << 1 | 1
using namespace std;

struct Node {
    double y1, y2, len;
    int covers;
} T[maxn << 2];
struct Node2 {
    double x, y1, y2;
    int isLeft;
} xNode[maxn];
double yNode[maxn];

bool cmp(Node2 a, Node2 b) {
    return a.x < b.x;
}

void pushUp(int l, int r, int rt) {
    if(T[rt].covers > 0)
        T[rt].len = T[rt].y2 - T[rt].y1;
    else if(r - l == 1) T[rt].len = 0.0;
    else T[rt].len = T[rt << 1].len + T[rt << 1 | 1].len;
}

void build(int l, int r, int rt) {
    T[rt].covers = 0;
    T[rt].y1 = yNode[l];
    T[rt].y2 = yNode[r];
    T[rt].len = 0.0;
    if(r - l == 1) return;
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
}

void update(Node2 x, int l, int r, int rt) {
    if(x.y1 == T[rt].y1 && x.y2 == T[rt].y2) {
        T[rt].covers += x.isLeft;
        pushUp(l, r, rt);
        return;
    }
    int mid = (l + r) >> 1;
    if(x.y2 <= yNode[mid]) update(x, lson);
    else if(x.y1 >= yNode[mid]) update(x, rson);
    else {
        Node2 x1 = x, x2 = x;
        x1.y2 = x2.y1 = yNode[mid];
        update(x1, lson);
        update(x2, rson);
    }
    pushUp(l, r, rt);
}

int main() {
    //freopen("stdin.txt", "r", stdin);
    int n, i, id, cas = 1;
    double x1, y1, x2, y2, sum;
    while(scanf("%d", &n), n) {
        for(i = id = 0; i < n; ++i) {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            yNode[id] = y1;
            xNode[id].x = x1;
            xNode[id].y1 = y1;
            xNode[id].y2 = y2;
            xNode[id++].isLeft = 1;

            yNode[id] = y2;
            xNode[id].x = x2;
            xNode[id].y1 = y1;
            xNode[id].y2 = y2;
            xNode[id++].isLeft = -1;
        }
        sort(yNode, yNode + id);
        build(0, id - 1, 1);
        sort(xNode, xNode + id, cmp);
        update(xNode[0], 0, id - 1, 1);
        for(i = 1, sum = 0.0; i < id; ++i) {
            sum += T[1].len * (xNode[i].x - xNode[i-1].x);
            update(xNode[i], 0, id - 1, 1);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n", cas++, sum); 
    }
    return 0;
}