/************************************************************* 
 * 丑数：只含因子2、3和5的数。第一个丑数是1，求第n个丑数。
 * Via: changmu
 *************************************************************/ 

int GetUglyNumber(int index)
{
	if (index <= 0) return 0;

	int *pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	int *pMultiply2 = pUglyNumbers;
	int *pMultiply3 = pUglyNumbers;
	int *pMultiply5 = pUglyNumbers;

	for ( ; nextUglyIndex < index; ++nextUglyIndex) {
		pUglyNumbers[nextUglyIndex] = min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);

		while (*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex]) ++pMultiply2;
		while (*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex]) ++pMultiply3;
		while (*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex]) ++pMultiply5;
	}

	int ugly = pUglyNumbers[index - 1];
	delete[] pUglyNumbers;

	return ugly;
}
