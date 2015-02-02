// Author: changmu
int getFirstNumBiggerThanK(int *data, int length, int k)
{
	int left = 0, right = length;

	while (left < right) {
		int mid = left + right >> 1;
		if (data[mid] <= k) left = mid + 1;
		else right = mid;
	}

	return left;
}

int getNumberOfK(int *data, int length, int k)
{
	if (data == NULL || length <= 0)
		return 0;

	return getFirstNumBiggerThanK(k) - getFirstNumBiggerThanK(k - 1);
}
