#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

#define maxn 1010
using namespace std;

struct Node {
    double u, v;
    friend bool operator<(const Node& a, const Node& b) {
        return a.u < b.u;
    }
} E[maxn];
int N, D;

int main() {
    int i, ok, id, ans, cas = 1;
    double x, y, d, flag;
    while(scanf("%d%d", &N, &D), N) {
        printf("Case %d: ", cas++);
        ok = 1; id = 0;
        for(i = 0; i < N; ++i) {
            scanf("%lf%lf", &x, &y);
            if(y > D) ok = 0;
            if(!ok) continue;
            d = sqrt(D * D - y * y);
            E[id].u = x - d;
            E[id++].v = x + d;
        }

        if(!ok) {
            printf("-1\n");
            continue;
        }

        sort(E, E + id);

        flag = E[0].v; ans = 1;
        for(i = 1; i < N; ++i) {
            if(E[i].u <= flag) {
                if(E[i].v <= flag) flag = E[i].v;
                continue;
            }
            ++ans; flag = E[i].v;
        }

        printf("%d\n", ans);
    }
    return 0;
}