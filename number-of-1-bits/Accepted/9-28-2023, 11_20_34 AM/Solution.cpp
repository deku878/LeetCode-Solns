// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        for(int i=0;i<32;i++){
            if(1<<i & n){
                count++;
            }
        }
        return count;
    }
};