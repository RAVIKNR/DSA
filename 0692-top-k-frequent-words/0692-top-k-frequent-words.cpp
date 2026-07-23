class Solution {
public:
     
       struct cmp {
        bool operator()(pair<int, string> &a, pair<int, string> &b) {
            if (a.first != b.first) {
                 return a.first > b.first;  
               
            }
          return a.second < b.second;  
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
          string element = it.first;
           pair<int,string>curr={frequency,element};
           
           if(pq.size()<k){
            pq.push(curr);
            continue;
           }
           else if(frequency==pq.top().first){
             if(pq.top().second>element){
                    pq.pop();
               pq.push(curr);
               continue;
             }
             else{
              continue;
             }
           }
           else if(frequency<pq.top().first){
             continue;
           }
           else{
               pq.pop();
               pq.push(curr);
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