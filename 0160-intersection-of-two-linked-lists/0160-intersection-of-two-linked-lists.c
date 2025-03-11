/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;

    struct ListNode *ptrA = headA;
    struct ListNode *ptrB = headB;

    // Traverse until both pointers are equal (either at the intersection or at NULL)
    while (ptrA != ptrB) {
        // Move ptrA to the next node, or switch to headB if it reaches the end of list A
        if (ptrA == NULL) {
            ptrA = headB;
        } else {
            ptrA = ptrA->next;
        }

        // Move ptrB to the next node, or switch to headA if it reaches the end of list B
        if (ptrB == NULL) {
            ptrB = headA;
        } else {
            ptrB = ptrB->next;
        }
    }

    // Either they meet at the intersection node or at NULL if there's no intersection
    return ptrB;
}