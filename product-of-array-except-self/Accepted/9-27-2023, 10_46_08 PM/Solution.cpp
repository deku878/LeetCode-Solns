// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    //what you have to do in this is that element ke aage wale element to bolte hai prefix aur baad wale ko bolte hai postfix sabse pehle indono ko 1 initialise krdo then multiply krte jao last tak do iteratons hungi one for prefix other for postfix
    int n=nums.size();
    vector<int>res(n);
    int prefix=1,postfix=1;
    for(int i=0;i<n;i++){
        res[i]=prefix;
        prefix*=nums[i];
    }
    for(int i=n-1;i>=0;i--){
        res[i]*=postfix;
        postfix*=nums[i];
    }
    return res;
}

};