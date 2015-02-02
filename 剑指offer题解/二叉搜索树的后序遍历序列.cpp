/************************************************************* 
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
 * 如果是则返回true，否则返回false。输入数据无重复元素。
 * Edit by changmu
 *************************************************************/ 

bool VerifySquenceOfBST(int *sequence, int length)
{
	if (sequence == NULL || length <= 0)
		return false;

	int root = sequence[length - 1];
	
	int i = 0;
	for ( ; i < length - 1; ++i)
		if (sequence[i] > sequence[root])
			break;

	int j = i;
	for ( ; j < length - 1; ++j)
		if (sequence[j] < root) return false;

	bool left = true;
	if (i) left = VerifySquenceOfBST(sequence, i);

	bool right = true;
	if (length - 1 > i)
		right = VerifySquenceOfBST(sequence + i, length - i - 1);

	return left && right;
}
