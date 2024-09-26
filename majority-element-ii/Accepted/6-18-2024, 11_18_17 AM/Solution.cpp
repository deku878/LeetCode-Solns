// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1=0;
        int el2=0;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 and nums[i]!=el2){
                cnt1=1;
                el1=nums[i];
            }
            else if(cnt2==0 and nums[i]!=el1){
                cnt2=1;
                el2=nums[i];
            }
            else if(el1==nums[i]){
                cnt1++;
            }
            else if(el2==nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int>k;
        cnt1=0;
        cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(el1==nums[i]){
                cnt1++;
            }
            if(el2==nums[i]){
                cnt2++;
            }
        }
        if(cnt1>(nums.size()/3)){
        k.push_back(el1);}
        if(cnt2>(nums.size()/3) and el1!=el2){
        k.push_back(el2);}
        return k;
    }
};