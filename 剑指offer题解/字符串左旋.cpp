/************************************************************* 
 * 把一个字符串前面若干个数字转移到字符串尾部。比如输入字符串
 * "abcdefg"和数字2，则结果为："cdefgab".
 *************************************************************/ 
char *LeftRotateString(char *pStr, int n)
{
	if (pStr == NULL || n < 1) return NULL;

	int length = strlen(pStr);
	if (n >= length) return pStr;

	char *pFirstStart = pStr;
	char *pFirstEnd = pStr + n - 1;
	char *pSecondStart = pStr + n;
	char *pSecondEnd = pStr + length - 1;

	Reverse(pFirstStart, pFirstEnd);
	Reverse(pSecondStart, pSecondEnd);
	Reverse(pFirstStart, pSecondEnd);
	
	return pStr;
}
