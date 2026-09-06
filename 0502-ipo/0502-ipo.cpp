class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        for(int i=0;i<capital.size();i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int>pq;
        int index=0;

        while(k--){
        while(index<v.size() && w>=v[index].first){
            pq.push(v[index].second);
            index++;
        }
            if(pq.empty()){
                break;
            }
            w+=pq.top();
            pq.pop();
         
        }
        return w;
    }

};