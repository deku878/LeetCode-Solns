// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold

class Solution {
public:
    int calc(vector<int>& nums, int threshold){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)nums[i]/(double)threshold);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int start=1;
        int end=*max_element(nums.begin(), nums.end());
        while(start<=end){
            int mid=start+(end-start)/2;
            if(calc(nums,threshold)>=calc(nums,mid)){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }
};