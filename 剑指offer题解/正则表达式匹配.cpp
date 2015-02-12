/************************************************************* 
 * 实现一个函数用来匹配包含'.'和'*'的正则表达式。
 *************************************************************/ 
bool match(char *str, char *pattern)
{
	if (str == NULL || pattern == NULL)
		return false;
	return matchCore(str, pattern);
}

bool matchCore(char *str, char *pattern)
{
	if (*pattern == '\0') {
		if (*str == '\0') return true;
		else return false;
	}

	if (*(pattern + 1) == '*') {
		if (*str == '\0')
			return matchCore(str, pattern + 2);
		else {
			if (*pattern == *str || *pattern == '.')
				return matchCore(str, pattern + 2) // let '*' match 0 ch
				|| match(str + 1, pattern); // match 1 ch
			else return matchCore(str, pattern + 2);
		}
	} else if (*pattern == *str || (*pattern == '.' && *str != '\0')) {
		return matchCore(str + . pattern + 1);
	} else return false;
}
