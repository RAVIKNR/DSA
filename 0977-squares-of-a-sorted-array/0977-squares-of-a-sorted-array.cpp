class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      vector<int>a;
      vector<int>b;
      vector<int>ans(nums.size());
      int i=0;
      int j=0;
      for(int i=0;i<nums.size();i++){
        if(nums[i]<0){
            a.push_back(nums[i]*nums[i]);
        }
        else{
            b.push_back(nums[i]*nums[i]);
        }
      }

      reverse(a.begin(),a.end());


      int id=0;
      while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]){
            ans[id]=a[i];
            i++;
            id++;
        }
        else{
            ans[id]=b[j];
            j++;
            id++;
        }
      }
      while(i<a.size()){
        ans[id]=a[i];
        id++;
        i++;
      }

      while(j<b.size()){
        ans[id]=b[j];
        id++;
        j++;
      }

      return ans;
      
    }
};