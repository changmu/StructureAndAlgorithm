/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *partition(struct ListNode *head, int x) {
	struct ListNode dummyLess;
	struct ListNode dummyGreater;
	struct ListNode *pLess, *pGreater;
	dummyLess.next = NULL;
	dummyGreater.next = NULL;
	pLess = &dummyLess;
	pGreater = &dummyGreater;

	struct ListNode *pNode = head, *pAfter = NULL;
	for ( ; pNode != NULL; pNode = pAfter) {
		pAfter = pNode->next;
		if (pNode->val < x) {
			pLess->next = pNode;
			pLess = pNode;
			pLess->next = NULL;
		} else {
			pGreater->next = pNode;
			pGreater = pNode;
			pGreater->next = NULL;
		}
	}
	pLess->next = dummyGreater.next;

	return dummyLess.next;
}
