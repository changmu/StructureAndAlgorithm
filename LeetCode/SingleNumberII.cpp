int singleNumber(int A[], int n) {
	const int W = sizeof(int) * 8;
	int bitCount[W];
	memset(bitCount, 0, sizeof(bitCount));
	int i, j, result = 0;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < W; ++j)
			if ((1 << j) & A[i])
				++bitCount[j];
	}

	for (i = 0; i < W; ++i)
		if (bitCount[i] % 3)
			result |= (1 << i);

	return result;
}
