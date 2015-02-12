int LastRemaining(int n, int m) // num of people, the mth to pop, num from 0 to n-1
{
	if (n < 1 || m < 1) return -1;

	int last = 0;
	for (int i = 2; i <= n; ++i)
		last = (last + m) % i;

	return last;
}
