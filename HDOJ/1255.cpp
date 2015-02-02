////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-09-24 23:25:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1255
////Problem Title: 
////Run result: Accept
////Run time:359MS
////Run memory:484KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 2002
#define lson l, mid, rt << 1
#define rson mid, r, rt << 1 | 1
using namespace std;

struct Node {
    double y1, y2, onceLen, moreLen;
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
    if(T[rt].covers > 1) {
        T[rt].moreLen = T[rt].y2 - T[rt].y1;
        T[rt].onceLen = 0.0;
    } else if(T[rt].covers == 1) {
        if(r - l == 1) {
            T[rt].moreLen = 0.0;
            T[rt].onceLen = T[rt].y2 - T[rt].y1;
            return;
        }
        T[rt].moreLen = T[rt << 1].onceLen + T[rt << 1 | 1].onceLen
                        + T[rt << 1].moreLen + T[rt << 1 | 1].moreLen;
        T[rt].onceLen = T[rt].y2 - T[rt].y1 - T[rt].moreLen;
    } else {
        if(r - l == 1) {
            T[rt].onceLen = T[rt].moreLen = 0.0;
            return;
        }
        T[rt].onceLen = T[rt << 1].onceLen + T[rt << 1 | 1].onceLen;
        T[rt].moreLen = T[rt << 1].moreLen + T[rt << 1 | 1].moreLen;
    }
}

void build(int l, int r, int rt) {
    T[rt].onceLen = T[rt].moreLen = 0.0;
    T[rt].covers = 0;
    T[rt].y1 = yNode[l];
    T[rt].y2 = yNode[r];
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
    int n, i, id, t;
    double x1, y1, x2, y2, sum;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
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
        for(i = 0, sum = 0.0; i < id - 1; ++i) {
            update(xNode[i], 0, id - 1, 1);
            sum += T[1].moreLen * (xNode[i + 1].x - xNode[i].x);
        }
        printf("%.2lf\n", sum); 
    }
    return 0;
}