#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;

int main() {
    double a[12], sum = 0;
    for(int i = 0; i < 12; ++i) {
        scanf("%lf", &a[i]);
        sum += a[i];
    }
    printf("$%.2lf\n", sum / 12.0);
    return 0;
}