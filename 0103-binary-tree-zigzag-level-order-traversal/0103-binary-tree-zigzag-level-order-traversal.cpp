/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);

        bool flag =true;
        while(!q.empty()){
        int lvlsize = q.size();
        int first=0;
        int last=lvlsize-1;
        vector<int>temp(lvlsize);
          while(lvlsize--){
            TreeNode*t = q.front();
            q.pop();
            if(flag){
                temp[first] = t->val;
                first++;
            } 
            else{
                temp[last] = t->val;
                last--; 
            }
            if(t->left!=NULL){
                q.push(t->left);
            }
            if(t->right!=NULL){
                q.push(t->right);
            }

          }
          ans.push_back(temp);
          flag=!flag;
        }
       return ans;
    }
};