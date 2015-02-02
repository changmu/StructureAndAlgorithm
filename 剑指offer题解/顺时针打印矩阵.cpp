/************************************************************* 
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
 * Edit by changmu
 *************************************************************/ 

void PrintMatrixInCircle(int **numbers, int columns, int rows, int start)
{
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	// 从左到右打印一行
	for (int i = start; i <= endX; ++i) {
		int number = numbers[start][i];
		printNumber(number);
	}

	// 从上到下打印
	if (start < endY) {
		for (int i = start; i <= endY; ++i)
			printNumber(numbers[i][endX]);
	}

	// 从右到左
	if (endX > start && endY > start) {
		for (int i = endX - 1; i >= start; --i)
			printNumber(numbers[endY][i]);
	}

	// 从下向上
	if (endX > start && endY > start + 1) {
		for (int i = endY - 1; i > start; --i)
			printNumber(numbers[i][start]);
	}
}
