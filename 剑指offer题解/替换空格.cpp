/*
** 题目：实现一个函数，把字符串中每个空格替换成'%20'，例如输入'We are happy.'，则输出'We%20are%20happy.'。只能在原字符串上做替换，并且保证输入的字符串后面有足够多的空余内存。
*/

/*
** 思路：先遍历一边字符串，获取空格符的个数，以此判断完成后的字符串长度，然后用两个指针p1指向新串结尾，p2指向原串结尾，两个指针同时向左边移动并替换。
*/

// length为字符串数组string的总容量
void ReplaceBlank(char string[], int length) {
	if (string == NULL || length <= 0) return;

	// originalLength为字符串string的实际长度
	int originalLength = 0;
	int numberOfBlank = 0;

	for (int i = 0; string[i]; ++i) {
		++originalLength;
		if (string[i] == ' ') ++numberOfBlank;
	}

	// newLength为空格替换后的长度
	int newLength = originalLength + numberOfBlank * 2;
	if (newLength > length) return;

	int indexOfOriginal = originalLength;
	int indexOfNew = newLegnth;

	for ( ; indexOfOriginal >= 0 && indexOfOriginal < indexOfNew; --indexOfOriginal) {
		if (string[indexOfOriginal] == ' ') {
			string[indexOfnew--] = '0';
			string[indexOfnew--] = '2';
			string[indexOfnew--] = '%';
		} else string[indexOfnew--] = string[indexOfOriginal];
	}
}

// via:changmu
