/*
** 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

/*
** 思路：从矩阵右上角元素x入手，若待查找值y比x小，那么x所在列就可以排除掉，若y比x大，那么x所在行就可以排除掉，若x==y就找到了。
*/

bool Find(int *matrix, int rows, int columns, int number) {
	bool found = false;

	if (matrix != NULL && rows && columns) {
		int row = 0, cloumn = columns - 1;

		while (row < rows && column >= 0) {
			if (matrix[row * cloumns + column] == number) {
				found = true; break;
			} else if (matrix[row * columns + column] > number)
				--column;
			else ++row;
		}
	}

	return found;
}

// via:changmu
