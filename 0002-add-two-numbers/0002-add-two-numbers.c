/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->val = 0; 
    dummyHead->next = NULL;
    
    struct ListNode* current = dummyHead;  
    int carry = 0; 

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry; 
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next; 
        }

    
        carry = sum / 10;

        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val = sum % 10;
        current->next->next = NULL;
        
    
        current = current->next;
    }


    struct ListNode* result = dummyHead->next;

    free(dummyHead);

    return result; 
}