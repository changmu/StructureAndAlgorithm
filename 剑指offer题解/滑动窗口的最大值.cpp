vector<int> maxInWindows(const vector<int>& num, int size)
{
	vector<int> maxInWindows;
	if (size <= 0 || num.size() < size) return maxInWindows;
	
	deque<int> index;
	for (int i = 0; i < size; ++i) {
		while (!index.empty() && num[i] >= num[index.back()])
			index.pop_back();

		index.push_back(i);
	}

	for (int i = size; i < num.size(); ++i) {
		maxInWindows.push_back(num[index.front()]);

		while (!index.empty() && num[i] >= num[index.back()])
			index.pop_back();

		if (!index.empty() && i - index.front() >= size)
			index.pop_front();

		index.push_back(i);
	}
	maxInWindows.push_back(num[index.front()]);

	return maxInWindows;
}
