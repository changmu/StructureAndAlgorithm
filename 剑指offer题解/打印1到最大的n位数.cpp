/************************************************************* 
 * 面试题12：打印1到最大的n位数
 * 输入数字n，按顺序打印出从1到最大的n位十进制数。比如输入3，
 * 则打印1、2、3...999.
 *************************************************************/ 

/* 非递归写法 */
void Print1ToMaxOfNDigits(int n)
{
	if (n <= 0) return;

	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
		PrintNumber(number);

	delete []number;
}

bool Increment(char *number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);

	++number[nLength - 1];
	for (int i = nLength - 1; i >= 0; --i) {
		int nSum = number[i] - '0' + nTakeOver;
		
		if (nSum > 9) {
			if (i == 0) isOverflow = true;
			else {
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		} else break;
	}

	return isOverflow;
}

void PrintNumber(char *number) 
{
	int head = 0;

	while (number[head] == '0') ++head;
	puts(number + head);
}

/* 递归写法 */
void Print1ToMaxOfNDigits(int n)
{
	if (n <= 0) return;

	char *number = new char[n + 1];
	number[n] = '\0';

	Print1ToMaxOfNDigitsRecursively(number, 0, n);

	delete []number;
}

void Print1ToMaxOfNDigitsRecursively(char *number, int index, int n)
{
	if (index == n) {
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; ++i) {
		number[i] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, index + 1, n);
	}
}
