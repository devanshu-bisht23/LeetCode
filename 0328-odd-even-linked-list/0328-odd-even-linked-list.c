/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {

    if(head==NULL|| head->next==NULL) return head;

    struct ListNode *ptr=head, *cont=head->next, *x=cont;

        

        while(cont!=NULL && cont->next!=NULL){
            ptr->next=ptr->next->next;
            ptr=ptr->next;
            cont->next=ptr->next;
            cont=cont->next;   
        }
        ptr->next=x;
return head;
}