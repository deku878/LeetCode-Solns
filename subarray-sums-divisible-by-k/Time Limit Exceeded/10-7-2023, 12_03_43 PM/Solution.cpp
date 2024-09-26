// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    vector<long long int> pf(nums.size());
    pf[0] = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        pf[i] = pf[i - 1] + nums[i];
    }
    long long int count = 0;
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i; j < nums.size(); j++) {
            if ((pf[j] - (i > 0 ? pf[i - 1] : 0)) % k == 0) {
                count++;
            }
        }
    }
    return count;
}
};