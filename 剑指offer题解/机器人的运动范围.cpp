int movingCount(int threshold, int rows, int cols)
{
	bool *visited = new bool[rows * cols];
	for (int i = 0; i < rows * cols; ++i)
		visited[i] = false;

	visited[0] = true;
	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
	delete[] visited;

	return count;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited)
{
	int count = 1;
	int dir[][2] = {0, 1, 0, -1, 1, 0, -1, 0};

	for (int i = 0; i < 4; ++i) {
		int R = row + dir[i][0];
		int C = col + dir[i][1];
		if (check(threshold, rows, cols, R, C) {
			visited[R * cols + C] = true;
			count += movingCountCore(threshold, rows, cols, R, C, visited);
		}
	}
}

int getDigitSum(int number)
{
	int sum = 0;
	while (number) {
		sum += number % 10;
		number /= 10;
	}

	return sum;
}

bool check(int threshold, int rows, int cols, int row, int col, bool *visited)
{
	return row >= 0 && col >= 0 && row < rows && col < cols && !vis[row * cols + col] && 
		getDigitSum(row) + getDigitSum(col) <= threshold;
}
