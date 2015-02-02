/************************************************************* 
 * 输入一个二叉树，输出它的镜像
 * Edit by changmu
 *************************************************************/ 
struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

void MirrorRecursively(BinaryTreeNode *pNode)
{
	if (pNode == NULL) return;
	if (pNode->m_pLeft == NULL && pNode->m_pRight == NULL)
		return;

	BinaryTreeNode *pTemp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = pTemp;

	MirrorRecursively(pNode->m_pLeft);
	MirrorRecursively(pNode->m_pRight);
}
