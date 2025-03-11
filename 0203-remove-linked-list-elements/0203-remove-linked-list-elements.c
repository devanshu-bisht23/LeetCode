/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    
    
    while(head!=NULL && head->val==val){ //to remove if val is at head 
        struct ListNode *p=head;
        head=head->next;
        free(p);
    }
    if(head==NULL) return 0; //cehcking that the list isnt empty after removing head value
    struct ListNode *prev=head, *cont=head->next;
    while(cont!=NULL){
        if(cont->val==val){
            prev->next=cont->next;
            free(cont);
            cont=prev->next;
        }else{ 
            prev=cont;
            cont=cont->next;
        }
    }
    return head;
}