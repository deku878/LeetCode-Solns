// https://leetcode.com/problems/k-th-symbol-in-grammar

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1){
            return 0;
        }
        else if(n==2){
            if(k==1){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            if(k==1){
                return 0;
            }
            else if(k==2*n-2){
                return 0;
            }
            else{
                return 1;
            }
        }
    }
};