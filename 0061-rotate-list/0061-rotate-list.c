struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;  // Edge case: empty list, single node, or no rotation
    }
    
    // Step 1: Calculate the length of the list
    struct ListNode* tail = head;
    int length = 1;
    while (tail->next != NULL) { // Reach the last node
        tail = tail->next;
        length++;
    }
    
    // Step 2: Reduce k if it's larger than the list length
    k = k % length;
    if (k == 0) {
        return head;  // No rotation needed if k is a multiple of length
    }
    
    // Step 3: Make the list circular
    tail->next = head;
    
    // Step 4: Move to the new tail (length - k) nodes from the start
    struct ListNode* newTail = head;
    for (int i = 1; i < length - k; i++) {
        newTail = newTail->next;
    }
    
    // Step 5: The new head is the next node after the new tail
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;  // Break the circle
    
    return newHead;
}