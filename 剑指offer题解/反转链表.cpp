/************************************************************* 
 * 面试题16：反转链表
 * 定义一个函数，输入一个链表的头结点，反转该链表并输出反转后
 * 链表的头结点。
 * Edit by changmu
 *************************************************************/ 
struct ListNode {
	int m_nValue;
	ListNode *m_pNext;
};

ListNode *ReverseList(ListNode *pHead)
{
	if (pHead == NULL) return NULL;

	ListNode *pReversedHead = NULL;
	ListNode *pNode = pHead;
	ListNode *pPrev = NULL;
	while (pNode != NULL) {
		ListNode *pNext = pNode->m_pNext;
		if (pNext == NULL) pReversedHead = pNode;
		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}

	return pReversedHead;
}

// 方法二：递归实现
ListNode *ReverseList(ListNode *pHead)
{
	if (pHead == NULL) return NULL;
	return ReverseListCore(NULL, pHead);
}

ListNode *ReverseListCore(ListNode *pPrev, ListNode *pNode)
{
	if (pNode == NULL) return pPrev;
	ListNode *pReversedHead = ReverseList(pNode, pNode->m_pNext);
	pNode->m_pNext = pPrev;
	return pReversedHead;
}
