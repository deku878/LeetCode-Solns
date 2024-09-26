// https://leetcode.com/problems/rotate-array

class Solution {
public:
   void reverse(int* nums, int start, int end){
    while(start < end){
        nums[start] ^= nums[end]; // swap elements
        nums[end] ^= nums[start];
        nums[start] ^= nums[end];
        start++;
        end--;
    }
}
void rotate(int* nums, int numsSize, int k){
    k %= numsSize;
    reverse(nums, 0, numsSize-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, numsSize-1);
}
};