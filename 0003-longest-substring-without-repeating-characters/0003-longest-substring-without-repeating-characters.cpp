class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int> f(256,0);
       int low=0;
        int res=0;
       for(int high=0;high<s.size();high++){
         f[s[high]]++;
         while(f[s[high]]>1){
            f[s[low]]--;
            low++;
         }
         int length=high-low+1;
         res=max(res,length);
       }
       return res;
    }
};