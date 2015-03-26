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
    bool hasCycle(ListNode *head) {
        ListNode *pSlow = head, *pQuick = head;

        while (pSlow != NULL && pQuick != NULL) {
            pSlow = pSlow->next;
            pQuick = pQuick->next;
            if (pQuick) pQuick = pQuick->next;
            if (pSlow && pSlow == pQuick)
                return true;
        }

        return false;
    }
};
