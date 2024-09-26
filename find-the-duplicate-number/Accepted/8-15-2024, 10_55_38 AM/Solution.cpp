// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //not modifying array and constant extra space
        int cnt=0;
        set<int>st;
        for(int i=0;i<nums.size();i++){
            //1 se n tak hai har integer
            if(st.find(nums[i])==st.end()){
                st.insert(nums[i]);
            }
            else{
                return nums[i];
            }
        }
        return -1;
    }
};