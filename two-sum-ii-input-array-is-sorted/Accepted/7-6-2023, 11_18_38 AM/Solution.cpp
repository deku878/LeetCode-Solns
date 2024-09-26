// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low=0;
        int high=numbers.size()-1;
        while(low<=high){
            if(numbers[high]+numbers[low]<target){
               low++;
            }
            else if(numbers[high]+numbers[low]>target){
                high--;
            }
            else if(numbers[high]+numbers[low]==target){
                return {low+1,high+1};
            }
        }
        return {-1,-1};
    }
};