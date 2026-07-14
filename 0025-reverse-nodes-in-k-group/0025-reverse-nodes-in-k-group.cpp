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

   void rev(ListNode*head,int size){
    ListNode*curr=head;
    ListNode*prev=NULL;
    while(size--){
        ListNode*nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
        return;
   }
    

    ListNode* reverseKGroup(ListNode* head, int k) {
      int size=k;
      ListNode* left=head;
      ListNode* right;
      ListNode* res=NULL;
      ListNode* prevleft=NULL;

      while(true){
         right=left;
         for(int i=0;i<size-1;i++){
            if(right==NULL){
                break;
            }
            right=right->next;
         }

       if(right){
        if(res==NULL){
            res=right;
          }
          ListNode*nextleft=right->next;
          rev(left,size);
          if(prevleft){
            prevleft->next=right;
          }
          prevleft=left;
          left=nextleft;
          
       }
       else{
        if(prevleft){
             prevleft->next=left;
        }
        if(res==NULL){
            res=left;
        }
        break;
       }

      }
      return res;

    }
};