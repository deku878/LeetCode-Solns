// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int candidate1 = 0, candidate2 = 0;
        
        // First pass: Find potential candidates
        for (int num : nums) {
            if (num == candidate1) {
                cnt1++;
            } else if (num == candidate2) {
                cnt2++;
            } else if (cnt1 == 0) {
                candidate1 = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                candidate2 = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        
        // Second pass: Verify the candidates
        cnt1 = 0;
        cnt2 = 0;
        for (int num : nums) {
            if (num == candidate1) {
                cnt1++;
            } else if (num == candidate2) {
                cnt2++;
            }
        }
        
        vector<int> result;
        int threshold = nums.size() / 3;
        if (cnt1 > threshold) {
            result.push_back(candidate1);
        }
        if (cnt2 > threshold && candidate2 != candidate1) {
            result.push_back(candidate2);
        }
        
        return result;
    }
};