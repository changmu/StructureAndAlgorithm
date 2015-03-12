int max(int a, int b) { return a > b ? a : b; }

int candy(int ratings[], int n) {
	int *count = (int *) malloc(sizeof(int) * n);
	int i, cnt, result = n;
	
	for (i = 1, count[0] = 0, cnt = 1; i < n; ++i)
		if (ratings[i] > ratings[i-1])
			count[i] = cnt++;
		else {
			cnt = 1;
			count[i] = 0;
		}
	for (i = n - 2, cnt = 1; i >= 0; --i)
		if (ratings[i] > ratings[i+1])
			count[i] = max(count[i], cnt++);
		else 
			cnt = 1;

	for (i = 0; i < n; ++i)
		result += count[i];

	free(count);

	return result;
}
