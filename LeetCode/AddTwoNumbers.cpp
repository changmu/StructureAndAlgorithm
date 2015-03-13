/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode dummy(-1), *pL1, *pL2, *pL;
		int carry = 0, val1, val2, val;

		for (pL1 = l1, pL2 = l2, pL = &dummy; pL1 || pL2;
				pL1 = pL1 == nullptr ? nullptr : pL1->next,
				pL2 = pL2 == nullptr ? nullptr : pL2->next,
				pL = pL->next) {
			val1 = pL1 == nullptr ? 0 : pL1->val;
			val2 = pL2 == nullptr ? 0 : pL2->val;
			val = val1 + val2 + carry;
			carry = 0;
			if (val >= 10) {
				val -= 10;
				carry = 1;
			}
			pL->next = new ListNode(val);
		}
		if (carry)
			pL->next = new ListNode(carry);

		return dummy.next;
	}
};
