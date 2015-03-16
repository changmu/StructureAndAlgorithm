/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteDuplicates(struct ListNode *head) {
	if (head == NULL)
		return head;
	struct ListNode *pPre = head, *pNode, *pNext;
	if (pPre->next != NULL)
		pNode = pPre->next;

	for ( ; pNode != NULL; pNode = pNext) {
		pNext = pNode->next;
		if (pNode->val == pPre->val) {
			pPre->next = pNext;
			free(pNode);
			pNode = NULL;
		} else {
			pPre = pNode;
		}
	}

	return head;
}
