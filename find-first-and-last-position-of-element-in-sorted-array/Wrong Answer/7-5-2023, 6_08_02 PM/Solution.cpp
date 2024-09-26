// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
int upper_bound(vector<int>&arr, int N, int X){
    int low=0;
    int high=N-1;
    int ans=N;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>X){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int lower_bound(vector<int>&arr, int N, int X){
    int low=0;
    int high=N-1;
    int ans=-1;
       while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=X){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> o(2);
    int countTarget = count(nums.begin(), nums.end(), target);
    
    if (countTarget == 0) {
        o[0] = -1;
        o[1] = -1;
    } else if (countTarget == 1) {
        int index = lower_bound(nums, nums.size(), target);
        if (nums[index] == target) {
            o[0] = index;
            o[1] = index;
        } else {
            o[0] = -1;
            o[1] = -1;
        }
    } else {
        int start = lower_bound(nums, nums.size(), target);
        int end = lower_bound(nums, nums.size(), target + 1) - 1;
        o[0] = start;
        o[1] = end;
    }
    
    return o;
}
};