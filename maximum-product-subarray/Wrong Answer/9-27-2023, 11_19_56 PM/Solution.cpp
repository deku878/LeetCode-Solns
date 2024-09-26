// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product=1;
        int maxproduct=INT_MIN;
        for(int i=0;i<nums.size();i++){
            product*=nums[i];
            maxproduct=max(product,maxproduct);
        }
                return maxproduct;
    }
};