#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

char buf[20];

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

int main() {
	int a0, a1, b0, b1, x, y, sign, c;
	char op;
	while(scanf("%d/%d%c%d/%d", &a0, &a1, &op, &b0, &b1) != EOF) {
		if(op == '+') 
			x = a0 * b1 + a1 * b0;
		else x = a0 * b1 - a1 * b0;
		y = a1 * b1;
		c = gcd(x, y);
		x /= c; y /= c;
		if(x == 0) puts("0");
		else if(x == y) puts("1");
		else {
			if(x * y < 0) {
				x = -abs(x);
				y = abs(y);
			} else {
				x = abs(x);
				y = abs(y);
			}
			if(x % y == 0) printf("%d\n", x);
			else printf("%d/%d\n", x, y);
		}
	}
	return 0;
}