/************************************************************* 
 * 打印出所有和为S的连续正整数序列(至少包含两个数)。
 *************************************************************/ 
void FindContinuousSequence(int sum)
{
	if (sum < 3) return;

	int small = 1, big = 2;
	int middle = sum + 1 >> 1;
	int curSum = small + big;

	for (; small < middle; curSum += ++big) {
		if (curSum == sum)
			PrintContinuousSequence(small, big);

		while (curSum > sum && small < middle) {
			curSum -= small++;
			if (curSum == sum)
				PrintContinuousSequence(small, big);
		}
	}
}

void PrintContinuousSequence(int small, int big)
{
	for (int i = small; i <= big; ++i)
		printf("%d ", i);
	printf("\n");
}
