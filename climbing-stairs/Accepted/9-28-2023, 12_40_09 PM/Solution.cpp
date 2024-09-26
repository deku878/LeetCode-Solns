// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        int start1=1;
        int start2=1;
        int ways=0;
        if(n==1){
            return 1;
        }
        for(int i=n-2;i>=0;i--){
            ways=start1+start2;
            start2=start1;
            start1=ways;
        }
        return ways;
    }
};