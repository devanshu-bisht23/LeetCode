/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* recursion(struct ListNode* y, struct ListNode* a) {
    if (y->next == a) {
        return y; 
    }
    struct ListNode* choppedhead = recursion(y->next, a);
    y->next->next = y; 
    y->next = NULL;    
    return choppedhead;   
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head==NULL || left == right) {
        return head;
    }

    struct ListNode *x = NULL, *y = head, *z = NULL, *a = head;
    int i;

    
    for (i = 1; i < left; i++) { 
            x = y;
            y = y->next;
        }
    for (i = 1; i <= right; i++) {
            a = a->next;  
        }
  
    struct ListNode* choppedhead = recursion(y, a);

   
    if (x != NULL) {  
            x->next = choppedhead; 
        } else { 
            head = choppedhead; 
        }

    y->next = a; 

    return head;
}