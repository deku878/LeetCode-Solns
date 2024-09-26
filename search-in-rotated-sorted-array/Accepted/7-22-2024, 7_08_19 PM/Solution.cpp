// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& a, int target) {
        int lo = 0;
        int hi = a.size() - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (a[mid] == target) {
                return mid;
            }
            if (a[lo] <= a[mid]) { // Left side is sorted
                if (a[lo] <= target && target <= a[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else { // Right side is sorted
                if (a[mid] <= target && target <= a[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        
        return -1; // Target not found
    }
};
