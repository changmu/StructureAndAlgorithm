#include <stdio.h>

int Add(int num1, int num2)
{
	int sum, carry;
	do {
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;

		num1 = sum;
		num2 = carry;
	} while (num2);

	return num1;
}

int main()
{
	int a, b;
	while (~scanf("%d%d", &a, &b))
		printf("%d\n", Add(a, b));
	return 0;
}
