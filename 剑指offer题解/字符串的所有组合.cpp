/************************************************************* 
 * 输出字符串的所有组合
 * Via changmu
 *************************************************************/ 

#include <stdio.h>
#include <string.h>

void CombinationCore(char *pString, int pos, int hasSelect, int tarLen, int length, char *vec)
{
	if (hasSelect == tarLen) {
		vec[hasSelect] = '\0';
		puts(vec);
		return;
	}
	
	vec[hasSelect] = pString[pos];
	CombinationCore(pString, pos + 1, hasSelect + 1, tarLen, length, vec);

	if (length - pos > tarLen - hasSelect)
		CombinationCore(pString, pos + 1, hasSelect, tarLen, length, vec);
}

void Combination(char *pString)
{
	if (pString == NULL) return;

	int length = strlen(pString);
	char *vec = new char[length + 1];
	for (int tarLen = 1; tarLen <= length; ++tarLen)
		CombinationCore(pString, 0, 0, tarLen, length, vec);

	delete []vec;
}

int main()
{
	char string[1000];
	while (gets(string))
		Combination(string);
	return 0;
}
