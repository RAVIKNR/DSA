class Solution {
public:
     
      struct cmp{
        bool operator()(pair<int,string>&a,pair<int,string>&b){
         if(a.first!=b.first){
           return a.first>b.first;
         }
         return a.second<b.second;
         }
      };

    vector<string> topKFrequent(vector<string>& words, int k) {
            unordered_map<string,int>f;
      vector<string>v;
      priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
      for(int i=0;i<words.size();i++){
        f[words[i]]++;
      }
      for(auto it:f){
        int frequency = it.second;
        string value = it.first;
        if(pq.size()<k){
            pq.push({frequency,value});
            continue;
        }
        else if(pq.top().first>frequency){
           continue;
        }
        else if(pq.top().first==frequency){
            if(pq.top().second>value){
                pq.pop();
            pq.push({frequency,value});
            }
            else{
                continue;
            }
        }
        else{
             pq.pop();
             pq.push({frequency,value});
             continue;
        }
      }
      while(!pq.empty()){
        v.push_back(pq.top().second);
        pq.pop();
      }
      reverse(v.begin(),v.end());
      return v;
    }
};