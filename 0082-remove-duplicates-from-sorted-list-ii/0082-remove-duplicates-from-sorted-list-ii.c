/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
     
     if(head==NULL || head->next==NULL) 
     {
        return head;
     }
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

    newNode->next=head;

    struct ListNode *prev= newNode;
         
    while(head!=NULL){
        if(head->next!=NULL && head->val == head->next->val )
        {

            while(head->next!=NULL && head->val==head->next->val){
                head=head->next; //head update, so we can work with prev next.
            
            }
            
            prev->next=head->next; //skip skip
        }else{
            prev=prev->next;
            
        }
        head=head->next;
    }


    return newNode->next; 


}