int canCompleteCircuit(int gas[], int cost[], int n) {
	int sum = 0, start = -1, i = 0, total = 0;

	for ( ; i < n; ++i) {
		sum += gas[i] - cost[i];
		total += gas[i] - cost[i];
		if (sum < 0) {
			start = i;
			sum = 0;
		}
	}

	return total < 0 ? -1 : ++start;
}
