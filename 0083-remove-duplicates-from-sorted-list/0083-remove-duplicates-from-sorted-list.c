/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct List Node *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *prev = head, *ahead = head->next,*p;

    while(ahead!=NULL){
        if(prev->val==ahead->val){
            prev->next=ahead->next;
            p=ahead;
            ahead=ahead->next;
            free(p);
        }else{
            prev=prev->next;
            ahead=ahead->next;
        }
    }
return head;
}