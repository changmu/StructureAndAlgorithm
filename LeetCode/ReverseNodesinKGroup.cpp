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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL || k <= 1)
            return head;

        ListNode *pBegin = head, *pEnd = head;
        ListNode *pNext = NULL, *pNode = NULL, *pTmp0, *pTmp1;
        for (int i = 1; i < k; ++i) {
            if (pEnd->next == NULL)
                return head;

            pEnd = pEnd->next;
        }
        pNext = pEnd->next;

        for (pNode = pBegin->next, pTmp0 = pBegin; pTmp0 != pEnd; ) {
            pTmp1 = pNode->next;
            pNode->next = pTmp0;
            pTmp0 = pNode;
            pNode = pTmp1;
        }

        pBegin->next = reverseKGroup(pNext, k);
        return pEnd;
    }
};
