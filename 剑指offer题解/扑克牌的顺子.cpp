/************************************************************* 
 * 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是
 * 连续的A~~K为1~~13，大小王都为0.
 *************************************************************/ 
bool IsContinuous(int *numbers, int length)
{
	if (numbers == NULL || length != 5)
		return false;

	int hashTable[14] = {0};
	int maxNum = 0;
	int minNum = 13;

	for (int i = 0; i < length; ++i) {
		if (numbers[i] != 0 && ++hashTable[numbers[i]] == 2)
			return false;
		else if (numbers[i] > maxNum)
			maxNum = numbers[i];
		else if (numbers[i] != 0 && numbers[i] < minNum)
			minNum = numbers[i];

		if (maxNum - minNum > 4) return false;
	}

	return true;
}
