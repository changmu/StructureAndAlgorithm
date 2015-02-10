/************************************************************* 
 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得
 * 它们的和正好是S，如果有有多对，输出任意一对即可。
 *************************************************************/ 
bool FindNumbersWithSum(int data[], int length, int sum, int *num1, int *num2)
{
	if (data == NULL || length < 2) return false;
	
	bool found = false;
	int *pHead = data;
	int *pTail = data + length - 1;
	while (pHead < pTail) {
		int currentSum = *pHead + *pTail;
		if (currentSum == sum) {
			*num1 = *pHead;
			*num2 = *pTail;
			found = true;
			break;
		} else if (currentSum < sum) ++pHead;
		else --pTail;
	}

	return found;
}
