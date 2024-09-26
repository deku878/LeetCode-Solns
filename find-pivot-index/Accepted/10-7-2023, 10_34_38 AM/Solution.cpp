// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        long long int sum1=0;
        bool check=false;
        long long int pos=-1;
        for(int i=0;i<nums.size();i++){
            if((sum-sum1-nums[i])==sum1){
                pos=i;
                check=true;
                break;
            }
            sum1+=nums[i];
        }
        if(check){
            return pos;
        }
        return -1;
    }
};