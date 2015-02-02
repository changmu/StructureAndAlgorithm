/************************************************************* 
 * 输出一个字符串的全排列
 * Edit by changmu
 *************************************************************/ 

void Permutation(char *pString)
{
	if (pString == NULL) return;
	
	Permutation(pString, pString);
}

void Permutation(char *pCurrent, const char *pString)
{
	if (*pCurrent == '\0') {
		puts(pString);
		return;
	}

	for (char *pCh = pCurrent; *pCh != '\0'; ++pCh) {
		char temp = *pCh;
		*pCh = *pCurrent;
		*pCurrent = temp;

		Permutation(pCurrent + 1, pString);

		temp = *pCh;
		*pCh = *pCurrent;
		*pCurrent = temp;
	}
}
