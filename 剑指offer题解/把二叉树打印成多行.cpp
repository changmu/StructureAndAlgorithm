// 从上到下按层打印二叉树，同一层节点按从左到右顺序打印。
void Print(BinaryTreeNode *pRoot)
{
	if (pRoot == NULL) return;

	std::queue<BinaryTreeNode *> nodes;
	nodes.push(pRoot);
	int nextLevel = 0;
	int toBePrinted = 1;

	while (!nodes.empty()) {
		BinaryTreeNode *pNode = nodes.front();
		nodes.pop();
		printf("%d ", pNode->m_nValue);

		if (pNode->m_pLeft != NULL) {
			nodes.push(pNode->m_pLeft);
			++nextLevel;
		}
		if (pNode->m_pRight != NULL) {
			nodes.push(pNode->m_pRight);
			++nextLevel;
		}
		
		if (--toBePrinted == 0) {
			toBePrinted = nextLevel;
			nextLevel = 0;
			printf("\n");
		}
	}
}
