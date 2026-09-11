class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>f;
        unordered_map<char,int>task;
        priority_queue<pair<int,char>>pq;

        for(int i=0;i<tasks.size();i++){
            task[tasks[i]]=1;
            f[tasks[i]]++;
        }
        for(auto it:f){
            pq.push({it.second,it.first});
        }
        int seat=1;

        while(!pq.empty()){
            vector<pair<int,char>>pull;
            while(!pq.empty()){
                pair<int,char>p=pq.top();
                pq.pop();
                if(seat>=task[p.second]){
                    if(p.first>1){
                        pq.push({p.first-1,p.second});
                    }
                    task[p.second]=seat+n+1;
                    break;
                }
                else{
                    pull.push_back({p.first,p.second});
                }
              
            }
            for(int i=0;i<pull.size();i++){
                pq.push(pull[i]);
            }
            seat++;
        }

           return seat-1;
    
    }
};