// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long int p=__builtin_popcount(n);
        if(p==1 and n>0){
            return true;
        }
        return false;
    }
};