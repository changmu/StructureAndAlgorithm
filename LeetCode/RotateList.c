/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *rotateRight(struct ListNode *head, int k) {
	if (head == NULL || k < 0) return head;

	int length = 0, count = 1;
	struct ListNode *pNode = head, *pTail = NULL;
	struct ListNode *pHead = NULL;

	while (pNode != NULL) {
		pTail = pNode;
		++length;
		pNode = pNode->next;
	}

	k %= length;
	if (k == 0) return head;

	length -= k;
	for (pNode = head; count != length; ++count)
		pNode = pNode->next;
	pHead = pNode->next;
	pNode->next = NULL;
	pTail->next = head;

	return pHead;
}
