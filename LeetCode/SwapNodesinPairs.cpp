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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *pNode1 = head, *pNode2 = head->next, *pNode3 = pNode2->next;
        pNode2->next = pNode1;
        pNode1->next = swapPairs(pNode3);
        return pNode2;
    }
};
