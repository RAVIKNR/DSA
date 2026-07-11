class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high=nums.size()-1;
        int low=0;
        while(low<=high){
            int guess= low+(high-low)/2;
            if(nums[guess]==target){
                return guess;
            }
            if(nums[guess]>nums[nums.size()-1]){   //part1
                        if(target<nums[guess]){
                            if(nums[0]>target){
                                low=guess+1;
                            }
                            else{
                                high=guess-1;
                            }

                        }
                        else{
                            low=guess+1;
                        }
            }
            else{
                if(nums[guess]>target){    //part2
                  high=guess-1;
                }
                else{
                      if(target>nums[nums.size()-1]){
                        high=guess-1;
                    }
                    else{
                        low=guess+1;
                    }
                }
            }
    }
            return -1;
    }
};