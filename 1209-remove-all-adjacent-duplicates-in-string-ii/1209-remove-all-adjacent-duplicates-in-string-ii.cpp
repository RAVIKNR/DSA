class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        string result;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push({s[i],1});
                continue;
            }
            if(st.top().first!=s[i]){
              st.push({s[i],1});
              continue;
            }
            if(st.top().second<k-1){
              st.top().second++;
              continue;
            }
          st.pop();
            
        }
          while(!st.empty()){
                while(st.top().second--){
                    result+=st.top().first;
                }
                st.pop();
            }
            reverse(result.begin(),result.end());
            return result;
    }
};