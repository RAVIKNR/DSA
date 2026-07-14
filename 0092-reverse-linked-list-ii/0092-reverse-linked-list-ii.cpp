/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    int times=right-left+1;
    int pos=1;
    ListNode*before=NULL;
    ListNode* t=head;

    if(left==right){
        return head;
    }
    if(head==NULL){
        return NULL;
    }

    while(pos<left){
      before=t;
      t=t->next;
      pos++;
    }


    ListNode* curr=t;
    ListNode* prev=NULL;
    while(times--){
      ListNode* nex=curr->next;
      curr->next=prev;
      prev=curr;
      curr=nex;
    }

    t->next=curr;
    if(pos==1){
        return prev;
    }
    before->next=prev;
    
    return head;

    }
};