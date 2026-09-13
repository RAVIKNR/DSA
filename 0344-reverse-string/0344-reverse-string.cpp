class Solution {
public:
    void reverseString(vector<char>& s) {
        
         int low=0;
            int high=s.size()-1;
            
            return reverse(low,high,s);

    }

      void reverse(int low, int high, vector<char>& s){

 if(high<=low){
                return ;
            }
            
           swap(s[low],s[high]);
            
            return reverse(low+1,high-1,s);
        }

};