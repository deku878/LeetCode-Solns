// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        //then we have to find the number of duplicates as well
        int previous=INT_MIN;
        int length=nums.size();
        int cnt=0;
        for(int i=0;i<length;i++){
            if(nums[i]!=previous){
                previous=nums[i];
                nums[j]=nums[i];
                j++;
                cnt++;
            }
        }
        return cnt;
    }
};