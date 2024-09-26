// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

class Solution {
public:
        bool isValid(vector<int>& bloomDay, int m, int k, int mid) {
        int bouquets = 0;
        int flowers = 0;
        
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            }
            else {
                flowers = 0;
            }
        }
        bouquets += flowers / k;
        return bouquets >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < (long long)m * k) {
            return -1;
        }
        
        int lo = 1;
        int hi = 1e9;
        int ans = -1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (isValid(bloomDay, m, k, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};