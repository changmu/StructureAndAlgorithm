/************************************************************* 
 * 把N个骰子扔在地上，所有骰子朝上一面的点数之和为S。输入N，
 * 打印出S的所有可能值出现的频率。
 *************************************************************/ 
const int g_maxValue = 6;
void PrintProbability(int number)
{
	if (number < 1) return;

	int *pProbabilities[2];
	pProbabilities[0] = new int[g_maxValue * number + 1];
	pProbabilities[1] = new int[g_maxValue * number + 1];
	for (int i = 0; i < g_maxValue * number + 1; ++i) {
		pProbabilities[0][i] = 0;
		pProbabilities[1][i] = 0;
	}

	int flag = 0;
	for (int i = 1; i <= g_maxValue; ++i)
		pProbabilities[flag][i] = 1;

	for (int k = 2; k <= number; ++k, flag = 1 - flag) {
		for (int i = 0; i < k; ++i)
			pProbabilities[1 - flag][i] = 0;

		for (int i = k; i <= k * g_maxValue; ++i) {
			pProbabilities[1 - flag][i] = 0;
			for (int j = 1; j <= i && j <= g_maxValue; ++j)
				pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
		}
	}

	double total = power((double)g_maxValue, number);
	for (int i = number; i <= g_maxValue * number; ++i) {
		double ratio = pProbabilities[flag][i] / total;
		printf("%d: %e\n", i, ratio);
	}
	
	delete[] pProbabilities[0];
	delete[] pProbabilities[1];
}
