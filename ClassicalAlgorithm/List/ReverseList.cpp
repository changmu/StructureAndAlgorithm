/************************************************************* 
 * ½«Á´±íÄæÐò
 *************************************************************/ 
struct ListNode {
    int val;
    ListNode *next;
};

ListNode *reverseList(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *pNode, *pNext, *pPre;

    pPre = head;
    pNode = head->next;
    pPre->next = NULL;

    while (pNode != NULL) {
        pNext = pNode->next;
        pNode->next = pPre;
        pPre = pNode;
        pNode = pNext;
    }

    return pPre;
}
