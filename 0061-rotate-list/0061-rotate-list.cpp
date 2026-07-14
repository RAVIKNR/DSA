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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        
        
        int length=1;
        ListNode* calc;
        calc=head;
        while(calc->next!=NULL){
           calc=calc->next;
          length++;
        }
        

        k=k%length;
        if (k == 0){
    return head;}


        ListNode* temp=head;
        for(int i=0;i<length-k-1;i++){    //n-k
           temp=temp->next;
        }


        ListNode* temp2=temp->next;
            calc->next=head;
            temp->next=NULL;
          return temp2;
    }
};