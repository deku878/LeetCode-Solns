// https://leetcode.com/problems/largest-perimeter-triangle

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size()-2;i++){
            int p=nums[i];
            int q=nums[i+1];
            int r=nums[i+2];
            if(p+q>r and r+p>q){
                sum=max(sum,p+q+r);
            }
        }
        return sum;
    }
};