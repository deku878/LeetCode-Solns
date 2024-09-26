// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    vector<int>arr(k,0);
        int sum=0;
     
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sum=sum%k;
            sum=(sum+k)%k; //handling negative modulo
            arr[sum]++;

        }
        
        int count=arr[0]; //edge case
        
      //nc2 ways to count
        for(int i=0;i<arr.size();i++)
            count+=((arr[i]*(arr[i]-1))/2);

        return count;
}
};