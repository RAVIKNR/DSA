class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>f;
        for(int i=0;i<s.size();i++){
            f[s[i]]++;
        }
        priority_queue<pair<int,char>>p;
        for(auto it:f){
            p.push({it.second,it.first});
        }
          string res = "";
        while(!p.empty()){
            if(res.empty() || p.top().second!=res.back()){
            pair<int,char>p1=p.top();
            p.pop();
                res.push_back(p1.second);
                p1.first--;
                
                if(p1.first>0){
                    p.push(p1);
                }
            }
            else{
                pair<int,char>p2=p.top();
                p.pop();
                if(p.empty()){
                    return "";
                }
                pair<int,char>p3=p.top();
                p.pop();
                res.push_back(p3.second);
                
               
                p3.first--;

                    p.push(p2);
                
                if(p3.first>0){
                    p.push(p3);
                }
            }
        }
        return res;
    }
};