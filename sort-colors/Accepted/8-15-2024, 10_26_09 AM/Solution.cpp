// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0=count(nums.begin(),nums.end(),0);
        int cnt1=count(nums.begin(),nums.end(),1);
        int cnt2=count(nums.begin(),nums.end(),2);
        vector<int>temp;
        for(int i=0;i<cnt0;i++){
            temp.push_back(0);
        }
        for(int i=0;i<cnt1;i++){
            temp.push_back(1);
        }
        for(int i=0;i<cnt2;i++){
            temp.push_back(2);
        }
        nums=temp;
    }
};