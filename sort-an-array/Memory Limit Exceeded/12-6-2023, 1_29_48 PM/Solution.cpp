// https://leetcode.com/problems/sort-an-array

class Solution {
public:
    vector<int>insert(vector<int>& nums,int temp){
        if(nums.size()==0 or temp>=nums[nums.size()-1]){
            nums.push_back(temp);
            return nums;
        }
        int val=nums[nums.size()-1];
        nums.pop_back();
        insert(nums,temp);
        nums.push_back(val);
        return nums;
    }
    vector<int> sortArray(vector<int>& nums) {
        //Base condition
        if(nums.size()==1){
            return nums;
        }
        //Hypothesis
        int temp=nums[nums.size()-1];
        nums.pop_back();
        sortArray(nums);
        insert(nums,temp);
        return nums;
    }
};