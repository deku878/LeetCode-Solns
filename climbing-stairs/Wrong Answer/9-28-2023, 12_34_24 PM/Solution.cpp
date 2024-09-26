// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        int start1=1;
        int start2=1;
        int ways=2;
        for(int i=n-3;i>=0;i--){
            ways+=start1;
            start1=ways;
        }
        return ways;
    }
};