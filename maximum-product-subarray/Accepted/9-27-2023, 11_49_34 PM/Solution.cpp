// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=*std::max_element(nums.begin(),nums.end());
        int currmax=1,currmin=1;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            int tmp=n*currmax;
            currmax=max({n*currmax,n*currmin,n});
            currmin=min({tmp,n*currmin,n});
            res=max(res,currmax);
        }
        return res;
    }
};