/************************************************************* 
 * 输入两个链表，找出它们的第一个公共结点。
 * via: changmu
 *************************************************************/ 
struct ListNode {
	int m_nValue;
	ListNode *m_pNext;
};

ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
	if (pHead1 == NULL || pHead2 == NULL)
		return NULL;

	unsigned int nLength1 = GetListLength(pHead1);
	unsigned int nLength2 = GetListLength(pHead2);
	int nLengthDif = nLength1 - nLength2;

	ListNode *pListHeadLong = pHead1;
	ListNode *pListHeadShort = pHead2;
	if (nLengthDif < 0) {
		pListHeadLong = pHead2;
		pListHeadShort = pHead1;
		nLengthDif = -nLengthDif;
	}

	for (int i = 0; i < nLengthDif; ++i)
		pListHeadLong = pListHeadLong->m_pNext;

	while (pListHeadLong != NULL && pListHeadShort != NULL && pListHeadShort != pListHeadLong) {
		pListHeadLong = pListHeadLong->m_pNext;
		pListHeadShort = pListHeadShort->m_pNext;
	}

	return pListHeadLong;
}

unsigned int GetListLength(ListNode *pHead)
{
	unsigned int nLength = 0;
	ListNode *pNode = pHead;

	for (; pNode != NULL; pNode = pNode->m_pNext)
		++nLength;
	
	return nLength;
}
