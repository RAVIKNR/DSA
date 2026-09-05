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
          int seat=0;
        while(!p.empty()){
            pair<int,char>p1=p.top();
            p.pop();
            if(seat==0 || p1.second!=res[seat-1]){
                res.push_back(p1.second);
                p1.first--;
                seat++;
                if(p1.first>0){
                    p.push(p1);
                }
            }
            else{
                if(p.empty()){
                    return "";
                }
                pair<int,char>p2=p.top();
                p.pop();
                res.push_back(p2.second);
                seat++;
                p2.first--;

                if(p2.first>0){
                    p.push(p2);
                }
                if(p1.first>0){
                    p.push(p1);
                }
            }
        }
        return res;
    }
};