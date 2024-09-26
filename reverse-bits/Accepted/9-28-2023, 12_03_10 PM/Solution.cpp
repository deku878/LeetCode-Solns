// https://leetcode.com/problems/reverse-bits

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int p=00000000000000000000000000000000;
        for(int i=0;i<32;i++){
            if(1<<i & n){
                p=(1<<(31-i))| p;
            }
        }
        return p;
    }
};