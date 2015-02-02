#include <stdio.h>
#include <math.h>

const double PI = acos(-1.0);

int main() {
    // freopen("stdin.txt", "r", stdin);
    int T;
    double X, Y;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        scanf("%lf%lf", &X, &Y);
        printf("Property %d: This property will begin eroding in year ", cas);
        printf("%.0lf.\n", ceil(PI * (X*X + Y*Y) / 100.0));
    }
    printf("END OF OUTPUT.\n");
    return 0;
}