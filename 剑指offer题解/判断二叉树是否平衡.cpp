bool IsBalanced(BinaryTreeNode *pRoot, int *pDepth)
{
	if (pRoot == NULL) {
		*pDepth = 0;
		return true;
	}

	int left, right;
	if (IsBalanced(pRoot->m_pLeft, &left) && IsBalanced(pRoot->m_pRight, &right)) {
		if (abs(left - right) > 1) 
			return false;
		
		*pDepth = max(left, right) + 1;
		return true;
	}

	return false;
}
