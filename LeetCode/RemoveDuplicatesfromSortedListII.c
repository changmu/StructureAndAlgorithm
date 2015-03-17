/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteDuplicates(struct ListNode *head) {
	if (head == NULL || head->next == NULL)
		return head;

	struct ListNode *pNode = head->next, *pNext;
	if (head->val == pNode->val) {
		for ( ; pNode != NULL && head->val == pNode->val; pNode = pNext) {
			pNext = pNode->next;
			head->next = pNext;
			free(pNode);
			pNode = NULL;
		}
		free(head);
		head = NULL;
		return deleteDuplicates(pNode);
	} else {
		head->next = deleteDuplicates(head->next);
		return head;
	}
}
