#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

#define maxn 105
const double g = 10.0;

int N, H, R, T;
double Y[maxn];

double cal(int k) {
    if(k < 0) return H;
    double t = (double)sqrt(2.0 * H / g);
    int m = (int)(k / t);
    if(m & 1) {
        double t1 = (m + 1) * t - k;
        return H - g * t1 * t1 / 2;
    } else {
        double t1 = k - m * t;
        return H - g * t1 * t1 / 2;
    }
}

int main() {
    int t, i;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", &N, &H, &R, &T);
        for(i = 0; i < N; ++i)
            Y[i] = cal(T - i);
        std::sort(Y, Y + N);
        for(i = 0; i < N; ++i)
            printf("%.2lf%c", Y[i] + 2.0*R*i/100.0, i==N-1?'\n':' ');
    }
    return 0;
}
