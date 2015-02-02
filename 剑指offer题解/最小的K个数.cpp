/************************************************************* 
 * 输入n个数，找出其中最小的K个数
 *************************************************************/ 
// 解法一：利用Partition函数，时间O(N)
int Partition(int *numbers, int n, int start, int end)
{
	int value = numbers[start];
	
	while (start < end) {
		while (start < end && numbers[end] >= value) --end;
		numbers[start] = numbers[end];
		while (start < end && numbers[start] <= value) ++start;
		numbers[end] = numbers[start];
	}
	numbers[start] = value;

	return start;
}

void GetLeastNumbers(int *input, int n, int *output, int k)
{
	if (input == NULL || output == NULL || k > n || n <= 0 || k <= 0)
		return;

	int start = 0;
	int end = n - 1;
	int index = end;

	while (index != k - 1) {
		if (index > k - 1) end = index - 1;
		else start = index + 1;
		index = Partition(input, n, start, end);
	}

	for (int i = 0; i < k; ++i)
		output[i] = input[i];
}

// 解法二：O(nlogk),适合海量数据
typedef multiset<int, greater<int> > intSet;
typedef multiset<int, greater<int> >::iterator setIterator;

void GetLeastNumbers(const vector<int>& data, intSet& leastNumbers, int k)
{
	leastNumbers.clear();

	if (k < 1 || data.size() < k) return;

	vector<int>::const_iterator.iter = data.begin();
	for ( ; iter != data.end(); ++iter) {
		if (leastNumbers.size() < k)
			leastNumbers.insert(*iter);
		else {
			setIterator iterGreatest = leastNumbers.begin();
			if (*iterGreatest > *iter) {
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}
}
