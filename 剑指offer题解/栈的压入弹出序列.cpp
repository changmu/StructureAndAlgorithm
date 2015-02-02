/************************************************************* 
 * 输入两个整数序列，第一个序列表示栈的压入序列，请判断第二个
 * 序列是否为该栈的弹出序列。假设压入栈的所有数字都不相等。
 * 例如12345是压栈序列，45321是一个合法弹出序列，43512却不是。
 * Edit by changmu
 *************************************************************/ 

bool IsPopOrder(const int *pPush, const int *pPop, int nLength)
{
	if (pPop == NULL || pPush == NULL || nLength <= 0)
		return false;

	bool result = false;
	const int *pNextPush = pPush;
	const int *pNextPop = pPop;
	stack<int> stackData;

	while (pNextPop - pPop < nLength) {
		while (stackData.empty() || stackData.top() != *pNextPop) {
			if (pNextPop - pPop == nLength) break;
			stackData.push(*pNextPush++);
		}

		if (stackData.top() != *pNextPop) break;
		stackData.pop();
		++pNextPop;
	}

	return stackData.empty();
}
