/************************************************************* 
 * 面试题14：调整数组顺序使奇数位于偶数前面
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得
 * 所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
 * Edit by changmu
 *************************************************************/ 

void ReorderOddEven(int *pData, int length)
{
	Reorder(pData, length, isOdd);
}

void Reorder(int *pData, int length, bool (*fun)(int))
{
	if (pData == NULL || length <= 0) return;

	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while (pBegin < pEnd) {
		while (pBegin < pEnd && func(*pBegin)) ++pBegin;
		while (pBegin < pEnd && !func(*pEnd)) --pEnd;

		if (pBegin < pEnd) {
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isOdd(int n)
{
	return n & 0x1;
}
