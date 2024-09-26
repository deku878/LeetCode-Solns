// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
                int n = nums.size();
        vector<int> lis(n, 1);
        vector<int> lds(n, 1);

        // Compute LIS for each element
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }

        // Compute LDS for each element
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }

        int maxMountainLength = 0;

        // Calculate the maximum length of bitonic subsequence
        for (int i = 1; i < n - 1; ++i) {
            if (lis[i] > 1 && lds[i] > 1) {
                maxMountainLength = max(maxMountainLength, lis[i] + lds[i] - 1);
            }
        }

        // Minimum removals to make a mountain array
        return n - maxMountainLength;
    }
};