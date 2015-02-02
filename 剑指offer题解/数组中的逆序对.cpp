/************************************************************* 
 * πÈ≤¢≈≈–Ú«ÛƒÊ–Ú∂‘
 * via: changmu
 *************************************************************/ 
int InversePairs(int *data, int length)
{
	if (data == NULL || length < 0) return 0;

	int *copy = new int[length];
	memcpy(copy, data, sizeof(int) * length);

	int count = InversePairsCore(data, copy, 0, length - 1);
	delete[] copy;

	return count;
}

int InversePairsCore(int *data, int *copy, int start, int end)
{
	if (start == end) {
		copy[start] == data[start];
		return 0;
	}

	int length = end - start >> 1;
	int left = InversePairsCore(copy, data, start, start + length);
	int right = InversePairsCore(copy, data, start + length + 1, end);

	int i = start + length;
	int j = end;
	int indexCopy = end;
	int count = left + right;

	while (i >= start && j > start + length) {
		if (data[i] > data[j]) {
			copy[indexCopy--] = data[i--];
			count += j - start - length;
		} else {
			copy[indexCopy--] = data[j--];
		}
	}

	for (; i >= start; --i)
		copy[indexCopy--] = data[i];
	for (; j > start + length; --j)
		copy[indexCopy--] = data[j];

	return count;
}
