class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int i=0;
        int n=candidates.size();
        vector<int>diary;
        vector<vector<int>>ans;
        int sum=0;
        com(i,n,diary,ans,target,candidates,sum);
        return ans;
    }

    void com(int i,int n,vector<int>&diary,vector<vector<int>>&ans,int target,vector<int>& candidates,int sum){
         
         
           if(sum==target){
            ans.push_back(diary);
            return;
         }
           if(sum>target){
            return;
         }
         if(i==n){
         return;
         }



        
        sum+=candidates[i];
        diary.push_back(candidates[i]);
        com(i,n,diary,ans,target,candidates,sum);
        sum-=candidates[i];
         diary.pop_back();

        com(i+1,n,diary,ans,target,candidates,sum);

    }



};