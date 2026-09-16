class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum=0;
        int closest=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++){
           int left=i+1;
           int right=nums.size()-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==target){
                    return sum;
                }
                else{
                   if(abs(closest-target)>abs(sum-target)) {
                    closest=sum;
                    
                   }

                   if(sum<target){
                    left++;
                   }

                 else{
                    right--;
                 }

                }
            }
        }
        return closest;
    }
};