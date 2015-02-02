#include <stdio.h>
#include <string.h>

#define maxn 10010

double L[maxn], inf;
int n, k;

bool cal(double mid) {
    int i, num = 0;
    for(i = 0; i < n; ++i)
        if((num += (int)(L[i] / mid)) >= k)
            return true;
    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    int i; inf = 0.0;
    double left, right, mid;
    for(i = 0; i < n; ++i) {
        scanf("%lf", &L[i]);
        if(L[i] > inf) inf = L[i];
    }
    left = 0.0; right = inf;
    for(i = 0; i < 100; ++i) {
        mid = (left + right) / 2;
        if(cal(mid)) left = mid;
        else right = mid;
    }
    printf("%.2lf\n", left);
}