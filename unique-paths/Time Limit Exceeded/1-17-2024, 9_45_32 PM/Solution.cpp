// https://leetcode.com/problems/unique-paths

class Solution {
public: 
    int countpath(int i,int j,int m,int n){
         if(i==n-1 and j==m-1){
            return 1;
        }
        else if(i>=n or j==m){
            return 0;
        }
        else{
            return countpath(i+1,j,m,n)+countpath(i,j+1,m,n);
        }
    }
    int uniquePaths(int m, int n) {
       return countpath(0,0,m,n);
    }
};