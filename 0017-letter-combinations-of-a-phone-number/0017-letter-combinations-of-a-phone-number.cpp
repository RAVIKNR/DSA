class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>f;

        f['2']="abc";
        f['3']="def";
        f['4']="ghi";
        f['5']="jkl";
        f['6']="mno";
        f['7']="pqrs";
        f['8']="tuv";
        f['9']="wxyz";

        vector<string>ans;
        string diary;
        int i=0;
        int n= digits.size();
        gen(i,digits,ans,diary,f,n);
        return ans;
    }

    void gen(int i,string digits,vector<string> &ans,string diary,unordered_map<char,string> f,int n){
       
       if(i==n){
        ans.push_back(diary);
        return;
       }

     string j = f[digits[i]];

     for(int k=0;k<j.size();k++){
        diary.push_back(j[k]);
        gen(i+1,digits,ans,diary,f,n);
        diary.pop_back();
     }

         
    
    }
 
  
         

};