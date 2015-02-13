//-- 实现一个函数，判断一棵二叉树是不是对称的。
//-- 如果一棵二叉树和它的镜像一样，那么它是对称的。
bool isSymmetrical(BinaryTreeNode *pRoot)
{
	return isSymmetrical(pRoot, pRoot);
}

bool isSymmetrical(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
	if (pRoot1 == NULL && pRoot2 == NULL)
		return true;
	else if (pRoot1 == NULL || pRoot2 == NULL)
		return false;
	
	if (pRoot1->m_nValue != pRoot2->m_nValue)
		return false;

	return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight) && 
		isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}
