// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    int sum = 0;
    int size = 0;
    int p = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        sum = 0;
        size = 0;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            size++;
            if (sum >= target) {
                p = min(p, size);
                break;
            }
        }
    }
    return p == INT_MAX ? 0 : p;
}
};