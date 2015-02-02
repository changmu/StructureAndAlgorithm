#include <stdio.h>
#include <math.h>

const double PI = acos(-1.0);
const double E = exp(1.0);

int main() {
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		printf("%d\n", (int)(log10(2*PI*n)/2+n*log10(n/E))+1);
	}
    return 0;
}