/************************************************************* 
 * 实现函数ComplexListNode *Clone(ComplexListNode *pHead);复制
 * 一个复杂链表。每个节点除了有一个m_pNext指针指向下一个节点外
 * 还有一个m_pSibling指向链表中的任意节点或者NULL。
 * Edit by changmu
 *************************************************************/ 
struct ComplexListNode {
	int m_nValue;
	ComplexListNode *m_pNext;
	ComplexListNode *m_pSibling;
};

void CloneNodes(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	while (pNode != NULL) {
		ComplexListNode *pClone = new ComplexListNode();
		pClone->m_nValue = pNode->m_nValue;
		pClone->m_pNext = pNode->m_pNext;
		pClone->m_pSibling = NULL;

		pNode->m_pNext = pClone;
		pNode = pClone->m_pNext;
	}
}

void ConnectionSiblingNodes(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	while (pNode != NULL) {
		ComplexListNode *pClone = pNode->m_pNext;
		if (pNode->m_pSibling != NULL)
			pClone.m_pSibling = pNode->m_pSibling->m_pNext;
		pNode = pClone->m_pNext;
	}
}

ComplexListNode *ReconnectNodes(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	ComplexListNode *pCloneHead = NULL;
	ComplexListNode *pCloneNode = NULL;

	if (pNode != NULL) {
		pCloneNode = pCloneHead = pNode->m_pNext;
		pNode->m_pNext = pCloneNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	while (pNode != NULL) {
		pCloneNode->m_pNext = pNode->m_pNext;
		pCloneNode = pCloneNode->m_pNext;
		pNode->m_pNext = pCloneNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	return pCloneHead;
}

ComplexListNode *Clone(ComplexListNode *pHead)
{
	if (pHead == NULL) return NULL;

	CloneNodes(pHead);
	ConnectionSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}
