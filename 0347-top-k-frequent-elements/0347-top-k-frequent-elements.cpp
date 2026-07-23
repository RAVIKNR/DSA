class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

          unordered_map<int,int>f;
          vector<int>v;
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++){
          f[nums[i]]++;
        }
       
        for(auto it:f){
          int frequency = it.second;
          int element = it.first;
           pair<int,int>curr={frequency,element};
           
           if(pq.size()<k){
            pq.push(curr);
            continue;
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

        return v;
    }
};