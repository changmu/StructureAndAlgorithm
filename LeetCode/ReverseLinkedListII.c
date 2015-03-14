/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseBetween(struct ListNode *head, int m, int n) {
	struct ListNode pHeadVirtual;
	pHeadVirtual.next = head;
	struct ListNode *pNode = &pHeadVirtual;

	struct ListNode *pPre = NULL;
	struct ListNode *pAfter = NULL;

	int countNum = 0, top = 0;
	struct ListNode **stack = (struct ListNode **)malloc(sizeof(struct ListNode *) * n);

	for ( ; pNode != NULL; pNode = pNode->next, ++countNum) {
		if (countNum < m)
			pPre = pNode;
		else if (countNum <= n)
			stack[top++] = pNode;
		else if (countNum == n + 1)
			pAfter = pNode;
		else break;
	}

	while (top--) {
		pPre->next = stack[top];
		pPre = pPre->next;
	}
	pPre->next = pAfter;

	free(stack);

	return pHeadVirtual.next;
}
