/************************************************************* 
 * 在字符串中找出第一个只出现一次的字符。
 * Via: changmu
 *************************************************************/ 

char FirstNotRepeatingChar(char *string)
{
	if (string == NULL) return '\0';

	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	memset(hashTable, 0, sizeof(hashTable));

	char *pHashKey = string;
	while (*pHashKey != '\0')
		++hashTable[*pHashKey++];

	pHashKey = string;
	for ( ; *pHashKey != '\0'; ++pHashKey)
		if (hashTable[*pHashKey] == 1)
			return *pHashKey;

	return '\0';
}
