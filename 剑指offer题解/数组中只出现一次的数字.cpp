/************************************************************* 
 * 一个整型数组里，除了两个数字外，其他的数字都出现了两次。编程
 * 找出这两个数字。要求时间复杂度O(N),空间复杂度O(1)
 *************************************************************/ 
void FindNumsAppearOnce(int data[], int length, int *num1, int *num2)
{
	if (data == NULL || length <= 0)
		return;

	int resultExclusiveOr = 0;
	for (int i = 0; i < length; ++i)
		resultExclusiveOr ^= data[i];

	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOr);

	for (int i = 0; i < length; ++i)
		if (data[i] & (1 << indexOf1)) 
			*num1 ^= data[i];
		else *num2 ^= data[i];
}

unsigned int FindFirstBitIs1(int num)
{
	int index = 0;
	for (; (num & 1) == 0; num >>= 1)
		++index;

	return index;
}
