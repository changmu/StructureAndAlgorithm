/************************************************************* 
 * 面试题15：链表中倒数第k个节点
 * 输入一个链表，输出该链表中倒数第k个节点。
 * Edit by changmu
 *************************************************************/ 
struct ListNode {
	int m_nValue;
	ListNode *m_pNext;
};

ListNode *FindKthToTail(ListNode *pListHead, int k)
{
	if (pListHead == NULL || k <= 0) return NULL;

	ListNode *pAhead = pListHead;
	ListNode *pBehind = NULL;

	for (int i = 0; i < k - 1; ++i) {
		if (pAhead->m_pNext == NULL) return NULL;
		pAhead = pAhead->m_pNext;
	}

	pBehind = pListHead;
	while (pAhead->m_pNext != NULL) {
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}

	return pBehind;
}
