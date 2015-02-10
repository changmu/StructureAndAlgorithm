/************************************************************* 
 * 例如输入字符串"I am a student."，则输出"student. a am I"。
 *************************************************************/ 
void Reverse(char *pBegin, char *pEnd)
{
	if (pBegin == NULL || pEnd == NULL)
		return;

	for (; pBegin < pEnd; ++pBegin, --pEnd) {
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
	}
}

char *ReverseSentence(char *pData)
{
	if (pData == NULL) return NULL;

	char *pBegin = pData;
	char *pEnd = pData;
	while (*pEnd != NULL) ++pEnd;
	--pEnd;

	Reverse(pBegin, pEnd);

	pBegin = pEnd = pData;
	while (*pBegin != NULL) {
		if (pBegin == ' ') pEnd = ++pBegin;
		else if (pEnd == ' ' || pEnd == '\0') {
			Reverse(pBegin, pEnd - 1);
			pBegin = ++pEnd;
		}
		else ++pEnd;
	}

	return pData;
}
