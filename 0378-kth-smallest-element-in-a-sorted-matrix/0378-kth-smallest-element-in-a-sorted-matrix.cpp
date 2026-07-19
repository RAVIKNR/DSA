class Solution {
public:
    int fun(int guess,vector<vector<int>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        int row=n-1;
        int col=0;
        int count=0;
        while(row>=0 && col<m){
            if(matrix[row][col]<=guess){
                count+=row+1;
                col++;
            }
            else{
                row--;
            }
        }
        return count;
    }
 

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
       int low=matrix[0][0];
       int high=matrix[n-1][m-1];
       int ans=0;
       int result=0;
       while(low<=high){
        int guess=low+(high-low)/2;
        ans=fun(guess,matrix);
        if(ans<k){
            low=guess+1;
        }
        else{
            result=guess;
            high=guess-1;
        }
       }
       return result;       
    }
};