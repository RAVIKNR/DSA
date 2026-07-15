class Solution {
public:
   
   long long fun(vector<int>& piles,int guess){
    long long eatspeed=0;
     for(int i=0;i<piles.size();i++){
        eatspeed+=piles[i]/guess;
        if(piles[i]%guess!=0){
          eatspeed++;
        }
     }
     return eatspeed;
   }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = *max_element(piles.begin(), piles.end());;
        int result=0;
      while(high>=low){
        int guess= low+(high-low)/2;
        long long eatspeed=fun(piles,guess);
        if(eatspeed<=h){
          result=guess;
          high=guess-1;
        }
        else{
          low=guess+1;
        }
        
      }
      return result;
    }
};