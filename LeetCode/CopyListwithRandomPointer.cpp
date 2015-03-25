/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#include <stdio.h>
#include <string.h>
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return head;

        RandomListNode *pNode, *pNext, *pNewHead;
        for (pNode = head; pNode != NULL; pNode = pNext->next) {
            pNext = new RandomListNode(pNode->label);
            pNext->next = pNode->next;
            pNode->next = pNext;
        }

        for (pNode = head; pNode != NULL; pNode = pNext->next) {
            pNext = pNode->next;
            if (pNode->random)
                pNext->random = pNode->random->next;
        }

        pNewHead = head->next;
        for (pNode = head; pNode != NULL; pNode = pNext) {
            pNext = pNode->next;
            pNode->next = pNext == NULL ? NULL : pNext->next;
        }
        printf("ok```````\n");

        return pNewHead;
    }
};

int main() {
    RandomListNode a(-1);
    Solution so;
    printf("%d\n", so.copyRandomList(&a)->label);
    return 0;
}
