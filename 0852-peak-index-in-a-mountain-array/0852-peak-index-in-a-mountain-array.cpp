class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int peak=0;
        int low=0;
        int high=arr.size();
        int res=-1;

        while(low<=high){
            int guess=low+(high-low)/2;
            if(arr[guess]>arr[guess+1]){
                       res=guess;
                 high=guess-1;
               
            }
             else{
                    low =guess+1;

             }
        }
        return res;
    }
};