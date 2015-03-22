/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode *p1, *p2, dummy;
    dummy.next = head;
    p1 = p2 = &dummy;
    for (int i = 0; i < n; ++i)
        p2 = p2->next;
    while (p2->next != NULL) {
        p2 = p2->next;
        p1 = p1->next;
    }
    p2 = p1->next;
    p1->next = p2->next;
    free(p2);
    return dummy.next;
}
