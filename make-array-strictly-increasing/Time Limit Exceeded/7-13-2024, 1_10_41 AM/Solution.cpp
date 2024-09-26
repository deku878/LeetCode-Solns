// https://leetcode.com/problems/make-array-strictly-increasing

class Solution {
public:
    int helper(int idx, int prev, vector<int> &arr1, vector<int> &arr2) {
        //Base case
        if(idx == arr1.size()) {
            return 0;
        }

        //Explore all paths;
        int replace = 1e9, not_replace = 1e9;

        //Replace
        int i = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if(i < arr2.size()) {
            replace = 1 + helper(idx + 1, arr2[i], arr1, arr2);            
        }

        //Not replace
        if(arr1[idx] > prev) {
            not_replace = helper(idx + 1, arr1[idx], arr1, arr2);
        }

        return min(replace, not_replace);
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int res = helper(0, -1, arr1, arr2);
        return res >= 1e9 ? -1 : res;
    }
};