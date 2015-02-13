// 找出给定二叉树节点的下一个中序遍历节点，每个节点有指向双亲的指针
BinaryTreeNode *GetNext(BinaryTreeNode *pNode)
{
	if (pNode == NULL) return NULL;

	BinaryTreeNode *pNext = NULL;
	if (pNode->m_pRight != NULL) {
		BinaryTreeNode *pRight = pNode->m_pRight;
		while (pRight->m_pLeft != NULL)
			pRight = pRight->m_pLeft;

		pNext = pRight;
	} else if (pNode->m_pParent != NULL) {
		BinaryTreeNode *pCurrent = pNode;
		BinaryTreeNode *pParent = pNode->m_pParent;
		while (pParent != NULL && pParent->m_pLeft != pCurrent) {
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}

		pNext = pParent;
	}

	return pNext;
}
