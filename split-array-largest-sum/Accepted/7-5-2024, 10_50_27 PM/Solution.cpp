// https://leetcode.com/problems/split-array-largest-sum

class Solution {
public:
    bool check(int a, int k, vector<int>& v) {
        int sum = 0, cnt = 1;
        for(auto x: v) {
            if(x > a) return false;
            sum += x;
            if(sum > a)
                sum = x, cnt++; 
        }
        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = 0, h = accumulate(nums.begin(), nums.end(), 0);
        while(l <= h) {
            int mid = (l + h) >> 1;
            if(check(mid, k, nums))
                h = mid - 1;
            else
                l = mid + 1;
        }

        return l;
    }
};