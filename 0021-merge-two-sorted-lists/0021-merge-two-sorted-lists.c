struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Handle edge cases where one of the lists is NULL
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    // Set up the head of the merged list
    struct ListNode *head = NULL, *tail = NULL;
    if (list1->val <= list2->val) {
        head = tail = list1;
        list1 = list1->next;
    } else {
        head = tail = list2;
        list2 = list2->next;
    }

    // Merge the lists by attaching nodes to the tail
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Attach any remaining nodes from either list
    if (list1 != NULL) {
        tail->next = list1; 
    } else {
        tail->next = list2;
    }

    return head;
}