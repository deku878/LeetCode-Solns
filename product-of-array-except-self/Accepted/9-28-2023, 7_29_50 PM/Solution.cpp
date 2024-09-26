// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int prefix=1;
    int postfix=1;
    vector<int>res(nums.size(),1);
    for(int i=0;i<nums.size();i++){
        res[i]*=prefix;
        prefix*=nums[i];
    }
    for(int i=nums.size()-1;i>=0;i--){
        res[i]*=postfix;
        postfix*=nums[i];
    }
    return res;
}

};