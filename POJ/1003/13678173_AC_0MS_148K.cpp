#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
	double a, sum, b;
	int cnt, i;
	while(scanf("%lf", &a), a) {
		sum = 0.0;
		for(i = 2; sum < a; ++i)
			sum += 1.0 / i;
		printf("%d card(s)\n", i - 2);
	}
	return 0;
}
