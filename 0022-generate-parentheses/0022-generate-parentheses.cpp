class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        string temp;
        vector<string>ans;
          gen(open,close,temp,ans,n);
         return ans;
    }

   void gen(int open,int close,string &temp,vector<string> &ans,int n){
        if(open==n && close==n){
           ans.push_back(temp);
           return;
        }

        if(open<n){
            temp.push_back('(');
            gen(open+1,close,temp,ans,n);
            temp.pop_back();
        }

        if(close<open){
            temp.push_back(')');
            gen(open,close+1,temp,ans,n);
            temp.pop_back();
        }
    }
};